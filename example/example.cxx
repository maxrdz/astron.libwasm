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
#endif
#ifdef HAVE_PANDA
#include <panda3d-webgl/pandaFramework.h>
#include <panda3d-webgl/pandaSystem.h>
#include <panda3d-webgl/genericAsyncTask.h>
#include <panda3d-webgl/asyncTaskManager.h>

// must use extern "C" to avoid mangling the function name
// or else the linker will claim these are undefined symbols.
extern "C" void init_libOpenALAudio();
extern "C" void init_libpnmimagetypes();
extern "C" void init_libwebgldisplay();

// Global stuff
PT(AsyncTaskManager) taskMgr = AsyncTaskManager::get_global_ptr();
PT(ClockObject) globalClock = ClockObject::get_global_clock();
#endif

#include "../src/client/ClientConnection.hxx"
using namespace astron;

class MyReactor : public ClientConnection {
public:
    MyReactor() {};
    void run(std::string astron_addr);
};

void MyReactor::run(std::string astron_addr) {
    connect(astron_addr, (uint32_t)0x5d7939, "v0.0.0");
    poll_forever(); // have the library create an emscripten main loop for you
}

int main(int argc, char* argv[]) {
#ifdef HAVE_PANDA
    // Initialize Panda libraries
    init_libOpenALAudio();
    init_libpnmimagetypes();
    init_libwebgldisplay();
    // Open a new window framework
    PandaFramework framework;
    framework.open_framework(argc, argv);
    WindowFramework *window = framework.open_window();
    // set clear buffer color
    window->get_graphics_window()->set_clear_color(LVecBase4(0.5f, 0.5f, 0.5f, 1.0f)); // r g b a
#endif

    /* It is VITAL that you dynamically allocate `MyReactor` via `new`.
     * If you allocate it on the stack, it will be cleared from memory as
     * soon as the emscripten main loop starts at `poll_forever()`.
     * You can allocate it on the stack if you call `poll_datagram()`
     * in your own loop that is in the scope where `MyReactor` is defined.
     */
    MyReactor *reactor = new MyReactor();
    reactor->run("127.0.0.1:8080"); // websocket proxy on loop back interface (proxying to client agent)

#ifdef HAVE_PANDA
    framework.main_loop();
    framework.close_framework();
#endif
    return 0;
}