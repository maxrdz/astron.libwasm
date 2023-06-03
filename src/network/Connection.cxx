/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file Connection.cxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#ifndef __EMSCRIPTEN__
#error Currently astron.libwasm only targets WebAssembly. Please build with Emscripten.
#endif // __EMSCRIPTEN__

#include <emscripten/websocket.h>
#include "Datagram.hxx"
#include "../client/messageTypes.hxx"
#include "Connection.hxx"

namespace astron { // open namespace

    Connection::Connection() : m_log("connection", "Connection") // constructor; creates websocket
    {
        // check websocket support on this browser
        EM_BOOL ws_support = emscripten_websocket_is_supported();

        if (!ws_support) {
            logger().error() << "WebSocket is not supported in your browser. Please upgrade your browser!";
            g_logger->js_flush();
            emscripten_force_exit(1); // exit w/ code 1 (error)
        }
    }

    Connection::~Connection() // destructor
    {
        if (m_socket) {
            disconnect(1000, "Connection instance destructor called with open web socket.");
        }
    }

    void Connection::em_main_loop(void *arg)
    {
        Connection* self = static_cast<Connection*>(arg);
        // if socket is not ready, don't do anything this 'frame'
        unsigned short socket_ready_state;
        emscripten_websocket_get_ready_state(self->get_em_socket(), &socket_ready_state);
        if (!socket_ready_state) return;
        self->poll_datagram();
    }

    /* Polls datagrams forever using an emscripten loop */
    void Connection::poll_forever() {
        emscripten_set_main_loop_arg(this->em_main_loop, this, this->em_loop_fps, this->em_simulate_infinite_loop);
    }

    void Connection::connect_socket(std::string url)
    {
        logger().info() << "Initializing WebSocket connection.";
        g_logger->js_flush();

        // create a new emscripten websocket
        EmscriptenWebSocketCreateAttributes ws_attributes;
        if (this->secure_websocket) { url.insert(0, "wss://"); } else { url.insert(0, "ws://"); }
        ws_attributes.url = url.c_str();
        ws_attributes.protocols = "binary";
        ws_attributes.createOnMainThread = EM_TRUE;
        m_socket = emscripten_websocket_new(&ws_attributes); // returns EMSCRIPTEN_WEBSOCKET_T

        if (m_socket < 0) { // if < 0, creation failed
            logger().fatal() << "Failed to create new WebSocket. API returned: " << std::to_string(m_socket);
            g_logger->js_flush();
        }

        // Set callbacks for the websocket states
        EMSCRIPTEN_RESULT err_res = emscripten_websocket_set_onerror_callback(m_socket, this, this->on_error);
        EMSCRIPTEN_RESULT msg_res = emscripten_websocket_set_onmessage_callback(m_socket, this, this->on_message);
        EMSCRIPTEN_RESULT open_res = emscripten_websocket_set_onopen_callback(m_socket, this, this->on_open);
        EMSCRIPTEN_RESULT close_res = emscripten_websocket_set_onclose_callback(m_socket, this, this->on_close);

        if (err_res < 0 || msg_res < 0 || open_res < 0 || close_res < 0) {
            logger().fatal() << "Failed to create Emscripten callbacks for WebSocket states.";
            g_logger->js_flush();
            emscripten_websocket_deinitialize();
            emscripten_force_exit(1); // exit w/ code 1 (error)
        }
    }

    EMSCRIPTEN_RESULT Connection::disconnect(unsigned short code, const char *reason)
    {
        if (!m_socket) {
            logger().warning() << "Connection::disconnect() called, but m_socket is 0 (no socket).";
            g_logger->js_flush();
            return EMSCRIPTEN_RESULT_SUCCESS;
        }
        // check ready state. only close if ready
        unsigned short socket_ready_state;
        emscripten_websocket_get_ready_state(m_socket, &socket_ready_state);

        if (socket_ready_state) {
            EMSCRIPTEN_RESULT res = emscripten_websocket_close(m_socket, code, reason);
            if (res != EMSCRIPTEN_RESULT_SUCCESS)
            {
                logger().fatal() << "Failed to close a ready websocket.";
                g_logger->js_flush();
                return res; // EMSCRIPTEN_RESULT_SUCCESS == 0
            }
        }
        EMSCRIPTEN_RESULT res = emscripten_websocket_delete(m_socket); // free socket handle from memory
        m_socket = 0; // reset m_socket value
        return res;
    }

    void Connection::poll_datagram() {
        //Datagram dg = Datagram();
        //dg.add_uint16((uint16_t)CLIENT_HELLO); // msg type
        //dg.add_uint32((uint32_t)0); // dc hash
        //dg.add_string("v0.0.0"); // version string
        //uint32_t dataLen = (uint32_t)dg.size();
        //void* data = (void*)dg.get_data();
        //emscripten_websocket_send_binary(m_socket, data, dataLen);
    }

    EM_BOOL Connection::on_error(int eventType, const EmscriptenWebSocketErrorEvent *websocketEvent, void *userData)
    {
        /* Since callback functions have to be static, we have no access to our class instance.
         * Instead, I pass 'this' as the userData void pointer argument so that we can then cast
         * the *userData to a Connection* pointer, which serves as the equivalent of 'this'.
         * NOTE: You can only access public members of the Connection instance that set this callback.
         */
        Connection* self = static_cast<Connection*>(userData);
        self->logger().fatal() << "Received Emscripten WebSocket error event!";
        g_logger->js_flush();
        return 1;
    }

    EM_BOOL Connection::on_message(int eventType, const EmscriptenWebSocketMessageEvent *websocketEvent, void *userData)
    {
        Connection* self = static_cast<Connection*>(userData);
        return 1;
    }

    EM_BOOL Connection::on_open(int eventType, const EmscriptenWebSocketOpenEvent *websocketEvent, void *userData)
    {
        Connection* self = static_cast<Connection*>(userData);
        self->logger().debug() << "Received Emscripten WebSocket open event!";
        g_logger->js_flush();
        return 1;
    }

    EM_BOOL Connection::on_close(int eventType, const EmscriptenWebSocketCloseEvent *websocketEvent, void *userData)
    {
        Connection* self = static_cast<Connection*>(userData);
        self->logger().debug() << "Received Emscripten WebSocket close event.";
        g_logger->js_flush();
        self->_call_handle_disconnect();
        return 1;
    }

    /* Called after disconnect occurs. Can be overridden by the user. */
    void Connection::handle_disconnect() {
    }

    /* needed for static callback to access this function */
    void Connection::_call_handle_disconnect() {
        this->handle_disconnect();
    }

    EMSCRIPTEN_WEBSOCKET_T Connection::get_em_socket() {
        return m_socket;
    }

} // close namespace astron