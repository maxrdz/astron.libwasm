/*
 * astron.libwasm
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file main.cxx
 * @author Max Rodriguez
 * @date 2023-04-25
 */

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#else
#define EMSCRIPTEN_KEEPALIVE
#endif

#include <iostream>

int main(int argc, char* argv[]) {
    std::cout << "Hello WASM!\n";
    return 0;
}
