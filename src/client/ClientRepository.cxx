/*
 * Copyright (c) 2014, kestred. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ClientRepository.cxx
 * @author kestred, Max Rodriguez
 * @date 2023-05-11
 */

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include "ClientRepository.hxx"
#include "messageTypes.hxx"

namespace astron   // open namespace
{

ClientRepository::ClientRepository()
{
}

ClientRepository::~ClientRepository()
{
}

void ClientRepository::connect(std::string uri, uint32_t dc_hash, std::string version)
{
    logger().info() << "Connecting to Client Agent at '" << uri << "' with version '" << version << "'";
    g_logger->js_flush();
    std::stringstream ss;
    ss << std::hex << dc_hash; // convert uint32_t to hex string
    logger().info() << "Client DC File Hash: 0x" << ss.str();
    g_logger->js_flush();
    connect_socket(uri); // connect websocket
}

} // close namespace