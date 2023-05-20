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
        // create a new emscripten websocket
        //m_socket = emscripten_websocket_new();
    }

    Connection::~Connection() // destructor
    {
        if (m_socket) {
            disconnect(0, "Connection instance destructor called with open web socket.");
        }
    }

    EMSCRIPTEN_RESULT Connection::disconnect(unsigned short code, const char *reason) {
        EMSCRIPTEN_RESULT res = emscripten_websocket_close(m_socket, code, reason);
        m_socket = 0; // reset m_socket value
        return res;
    }

} // close namespace astron