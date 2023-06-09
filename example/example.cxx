/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file example.cxx
 * @author Max Rodriguez
 * @date 2023-06-05
 */

#include "example.hxx"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

#ifdef HAVE_PANDA
#include <panda3d-webgl/pandaFramework.h>
#include <panda3d-webgl/pandaSystem.h>
#include <panda3d-webgl/genericAsyncTask.h>
#include <panda3d-webgl/asyncTaskManager.h>
#include <panda3d-webgl/cardMaker.h>
#include <panda3d-webgl/pandaNode.h>
#include <panda3d-webgl/nodePath.h>
#endif

using namespace astron;

void MyReactor::run(std::string astron_addr) {
    connect(astron_addr, (uint32_t)0x5d7939, "v0.0.0");
#ifdef HAVE_PANDA
    // add our datagram poll task
    taskMgr->add(new GenericAsyncTask("Calls poll_datagram()", &astron_poll, this));
#else
    poll_forever(); // have the library create an emscripten main loop for you
#endif
}

#ifdef HAVE_PANDA
AsyncTask::DoneStatus MyReactor::astron_poll(GenericAsyncTask *task, void *data) {
    MyReactor* app = static_cast<MyReactor*>(data);
    app->poll_till_empty();
    return AsyncTask::DS_cont; // repeat next panda frame
}
#endif

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

    window->enable_keyboard(); // Enable keyboard detection
    window->setup_trackball(); // Enable default camera movement

    // create a quad to test
    CardMaker quad = CardMaker("card");
    quad.set_frame_fullscreen_quad();
    PT(PandaNode) quad_node = quad.generate(); // equivalent of std::shared_ptr, but panda manages references
    // make a nodepath object for quad
    NodePath quad_np = NodePath(quad_node);
    quad_np.reparent_to(window->get_render());
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
    // start the framework main loop
    framework.main_loop();
    framework.close_framework();
#endif
    return 0;
}