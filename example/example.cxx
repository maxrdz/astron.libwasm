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
    void run(std::string astron_addr);
};

void MyReactor::run(std::string astron_addr) {
    connect(astron_addr, (uint32_t)0, "v0.0.0");
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
    MyReactor reactor;
    reactor.run("127.0.0.1"); // MD on loop back interface

#ifdef HAVE_PANDA
    framework.main_loop();
    framework.close_framework();
    return 0;
#endif
}