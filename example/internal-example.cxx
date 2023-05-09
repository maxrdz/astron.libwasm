/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file internal-example.cxx
 * @author Max Rodriguez
 * @date 2023-04-30
 */

#include "../src/internal/InternalConnection.hxx"
using namespace astron;

class MyReactor : public InternalConnection {
public:
    void run(std::string astron_addr, channel_t channel);

protected:
    void handle_datagram(Datagram &dg, DatagramIterator &dgi); // inherited from InternalConnection
};

void MyReactor::run(std::string astron_addr, channel_t channel) {
    connect(astron_addr);
    set_conn_name("MyReactor");
    subscribe_channel(channel);
    poll_forever();
}

void MyReactor::handle_datagram(Datagram &dg, DatagramIterator &dgi) {
    uint8_t num_receivers = dgi.read_uint8();
    channel_t* receivers = new channel_t[num_receivers];
    for (uint8_t i = 0; i < num_receivers; ++i) {
        receivers[i] = dgi.read_channel();
    }
    channel_t sender = dgi.read_channel();
    uint16_t message_type = dgi.read_uint16();

    switch(message_type) {
        case CLIENTAGENT_OPEN_CHANNEL: // example usage
            // do cool stuff
            break;
        default:
            // do anything I want to do on unexpected or ignored message type
            break;
    }
    delete [] receivers;
}

int main(int argc, char* argv[]) {
    MyReactor reactor;
    reactor.run("127.0.0.1", 1057); // MD on loop back interface
}