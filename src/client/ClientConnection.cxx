/*
 * Copyright (c) 2014, kestred. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ClientConnection.cxx
 * @author kestred, Max Rodriguez
 * @date 2023-05-11
 */

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include "ClientConnection.hxx"
#include "messageTypes.hxx"

namespace astron { // open namespace

    ClientConnection::ClientConnection() : m_log("msgdir", "Client Connection") {
        logger().info() << "Initialized Client Connection.";
        g_logger->js_flush();
        /*
         * We have to explicitly call the `js_flush()` method to make the `emscripten_log()` call.
         * Let me explain:
         *      The original Astron logger makes continuous writes to the `std::cout` stream as it
         *      forms the log output. Targeting Web Assembly with Emscripten, `std::cout` isn't printed
         *      to the Javascript console unless we call `emscripten_log()` via the Emscripten API ("emscripten.h").
         *
         *      The astron.libwasm implementation uses a modified Logger module that, instead of writing directly
         *      to the `std::cout` stream, it writes into a `std::string` buffer. Then, once `js_flush()` is
         *      called, `emscripten_log()` is called (passing the string buffer) and clears the string buffer.
         */
    }

    void ClientConnection::connect(std::string uri, uint32_t dc_hash, std::string version) {
    }

    void ClientConnection::disconnect() {
    }

} // close namespace