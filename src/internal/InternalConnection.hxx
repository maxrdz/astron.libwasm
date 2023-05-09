/*
 * Copyright (c) 2014, kestred. All rights reserved.
 * Copyright (c) 2013, Alex Mault. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file InternalConnection.hxx
 * @author kestred, Alex Mault, Max Rodriguez
 * @date 2023-05-09
 */

#ifndef ASTRON_LIBWASM_INTERNALCONNECTION_HXX
#define ASTRON_LIBWASM_INTERNALCONNECTION_HXX

#include "../network/Connection.hxx"
#include "../network/DatagramIterator.hxx"

namespace astron { // open namespace

    class InternalConnection : public Connection {
    public:
        InternalConnection();

        // ------------- Control Messages ------------- //
        void subscribe_channel(channel_t channel);
        void unsubscribe_channel(channel_t channel);
        void subscribe_range(channel_t lo, channel_t hi);
        void unsubscribe_range(channel_t lo, channel_t hi);
        void add_post_remove(const Datagram &dg);
        void clear_post_removes();
        void set_conn_url(std::string uri);
        void set_conn_name(std::string name);

    protected:
        virtual void handle_datagram(const Datagram &dg, DatagramIterator &dgi);

    private:
        void handle_datagram(const Datagram &dg);
    };
} // close namespace

#endif //ASTRON_LIBWASM_INTERNALCONNECTION_HXX