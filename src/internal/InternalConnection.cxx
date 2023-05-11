/*
 * Copyright (c) 2014, kestred. All rights reserved.
 * Copyright (c) 2013, Alex Mault. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file InternalConnection.cxx
 * @author kestred, Alex Mault, Max Rodriguez
 * @date 2023-05-09
 */

#include "InternalConnection.hxx"
#include "messageTypes.hxx"

namespace astron { // open namespace

    InternalConnection::InternalConnection() {
    }

    void InternalConnection::handle_datagram(const Datagram &dg) {
        uint8_t channels = 0;
        DatagramIterator dgi(dg);

        try {
            channels = dgi.read_uint8();
            DatagramIterator msg_dgi(dg, 1 + channels * sizeof(channel_t));
            handle_datagram(dg, msg_dgi);

        } catch (DatagramIteratorEOF &e) {
            // Really, if this has been sent to us by the MD... we really shouldn't have an issue.
            // But as always, better safe than sorry.
            std::cout << "Detected truncated datagram in handle_datagram" << std::endl;
        }
    }

    void InternalConnection::handle_datagram(const Datagram &dg, DatagramIterator &dgi) {
        // overwrite method
    }

    // ------------- Control Messages ------------- //

    void InternalConnection::subscribe_channel(channel_t channel) {
        Datagram dg(CONTROL_ADD_CHANNEL);
        dg.add_channel(channel);
        send_datagram(dg);
    }

    void InternalConnection::unsubscribe_channel(channel_t channel) {
        Datagram dg(CONTROL_REMOVE_CHANNEL);
        dg.add_channel(channel);
        send_datagram(dg);
    }

    void InternalConnection::subscribe_range(channel_t lo, channel_t hi) {
        Datagram dg(CONTROL_ADD_RANGE);
        dg.add_channel(lo);
        dg.add_channel(hi);
        send_datagram(dg);
    }

    void InternalConnection::unsubscribe_range(channel_t lo, channel_t hi) {
        Datagram dg(CONTROL_REMOVE_RANGE);
        dg.add_channel(lo);
        dg.add_channel(hi);
        send_datagram(dg);
    }

    void InternalConnection::add_post_remove(const Datagram &post) {
        Datagram dg(CONTROL_ADD_POST_REMOVE);
        dg.add_blob(post);
        send_datagram(dg);
    }

    void InternalConnection::clear_post_removes() {
        send_datagram(Datagram(CONTROL_CLEAR_POST_REMOVES));
    }

    void InternalConnection::set_conn_url(std::string uri) {
        Datagram dg(CONTROL_SET_CON_URL);
        dg.add_string(uri);
        send_datagram(dg);
    }

    void InternalConnection::set_conn_name(std::string name) {
        Datagram dg(CONTROL_SET_CON_NAME);
        dg.add_string(name);
        send_datagram(dg);
    }

} // close namespace astron