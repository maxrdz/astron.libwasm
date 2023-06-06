/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file Connection.hxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#ifndef ASTRON_LIBWASM_NETWORKCLIENT_HXX
#define ASTRON_LIBWASM_NETWORKCLIENT_HXX

#ifndef __EMSCRIPTEN__
#error Currently astron.libwasm only targets WebAssembly. Please build with Emscripten.
#endif // __EMSCRIPTEN__

#include <emscripten/websocket.h>
#include "../util/Logger.hxx"
#include "Datagram.hxx"

namespace astron { // open namespace

    class Connection {
    public:
        Connection();
        ~Connection();

        // logger returns the Connection log category.
        inline LogCategory& logger() {
            return m_log;
        }
        void connect_socket(std::string url); // does not send Astron messages, just connects the websocket
        void poll_forever();
        void send_datagram(const DatagramPtr &dg);
        void poll_datagram();

        EMSCRIPTEN_RESULT disconnect(unsigned short code, const char *reason);
        EMSCRIPTEN_WEBSOCKET_T get_em_socket();
        void _call_handle_disconnect(); // needed for static callback to access this function

    protected:
        LogCategory m_log;
        bool secure_websocket = false; // default ws://
        inline void set_secure_websocket(bool value) {
            secure_websocket = value;
        }
        virtual void handle_disconnect();

    private:
        static void em_main_loop(void *arg);
        int em_loop_fps = 60;
        int em_simulate_infinite_loop = 0;
        EMSCRIPTEN_WEBSOCKET_T m_socket = 0; // int

        static EM_BOOL on_error(int eventType,
                                const EmscriptenWebSocketErrorEvent *websocketEvent __attribute__((nonnull)),
                                void *userData);
        static EM_BOOL on_open(int eventType,
                               const EmscriptenWebSocketOpenEvent *websocketEvent __attribute__((nonnull)),
                               void *userData);
        static EM_BOOL on_close(int eventType,
                                const EmscriptenWebSocketCloseEvent *websocketEvent __attribute__((nonnull)),
                                void *userData);
        static EM_BOOL on_message(int eventType,
                                  const EmscriptenWebSocketMessageEvent *websocketEvent __attribute__((nonnull)),
                                  void *userData);
    };
} // close namespace

#endif //ASTRON_LIBWASM_NETWORKCLIENT_HXX