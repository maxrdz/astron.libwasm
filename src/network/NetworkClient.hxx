/*
 * Copyright (c) 2014, Astron Contributors. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file NetworkClient.hxx
 * @author Astron Contributors
 * @date 2023-04-30
 */

#ifndef ASTRON_LIBWASM_NETWORKCLIENT_HXX
#define ASTRON_LIBWASM_NETWORKCLIENT_HXX

#include <boost/asio.hpp>
#include "Datagram.hxx"

class NetworkClient {
protected:
    NetworkClient();
    NetworkClient(boost::asio::ip::tcp::socket *socket);
    virtual ~NetworkClient();
    void set_socket(boost::asio::ip::tcp::socket *socket);

    virtual void network_datagram(Datagram &dg) = 0;
    virtual void network_disconnect() = 0;
    void network_send(Datagram &dg);
    void do_disconnect();
    bool is_connected();

    boost::asio::ip::tcp::socket *m_socket;

private:
    void start_receive();
    void handle_size(const boost::system::error_code &ec, size_t bytes_transferred);
    void handle_data(const boost::system::error_code &ec, size_t bytes_transferred);

    uint8_t m_size_buf[2];
    uint8_t* m_data_buf;
    dgsize_t m_data_size;
    bool m_is_data;
};

#endif //ASTRON_LIBWASM_NETWORKCLIENT_HXX
