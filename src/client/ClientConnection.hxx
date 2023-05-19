/*
 * Copyright (c) 2014, kestred. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ClientConnection.hxx
 * @author kestred, Max Rodriguez
 * @date 2023-05-11
 */

#ifndef ASTRON_LIBWASM_CLIENTCONNECTION_HXX
#define ASTRON_LIBWASM_CLIENTCONNECTION_HXX

#include "../util/Logger.hxx"
#include "../network/Connection.hxx"

namespace astron { // open namespace
// Implementation Notes:
//     If necessary connection can subclass another class (maybe NetworkClient for example);
//     However, any inherited virtual functions must be implemented. Subclasses of connection
//     should only be required to implement handle_datagram.
    class ClientConnection : public Connection {
    public:
        ClientConnection();

        // connect starts a connection to the server, negotiates Hello and starts sending
        // heartbeats periodically. It returns after negotiation is complete.
        void connect(std::string uri, uint32_t dc_hash, std::string version);

        // disconnect cleanly closes the connection.
        // Internally: Sends a CLIENT_DISCONNECT, and waits for connection to close.
        void disconnect();
    };
} // close namespace

#endif //ASTRON_LIBWASM_CLIENTCONNECTION_HXX