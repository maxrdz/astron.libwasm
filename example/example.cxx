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

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include "../src/client/ClientConnection.hxx"
using namespace astron;

class MyReactor : public ClientConnection {
public:
    void run(std::string astron_addr);
};

void MyReactor::run(std::string astron_addr) {
    connect(astron_addr, (uint32_t)0, "v0.0.0");
    poll_forever();
}

int main(int argc, char* argv[]) {
    MyReactor reactor;
    reactor.run("127.0.0.1"); // MD on loop back interface
}