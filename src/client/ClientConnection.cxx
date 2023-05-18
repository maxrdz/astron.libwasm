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
    }

    void ClientConnection::connect(std::string uri, uint32_t dc_hash, std::string version) {
        logger().info() << "Connecting to Client Agent at '" << uri << "' with version '" << version << "'";
        g_logger->js_flush();
        logger().debug() << "Client DC Hash: 0x" << std::hex << dc_hash;
        g_logger->js_flush();
    }

    void ClientConnection::disconnect() {
    }

} // close namespace