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
#include <emscripten/html5.h>
#endif

#ifdef HAVE_PANDA
#include <panda3d-webgl/pandaFramework.h>
#include <panda3d-webgl/pandaSystem.h>
#include <panda3d-webgl/windowProperties.h>
#include <panda3d-webgl/genericAsyncTask.h>
#include <panda3d-webgl/asyncTaskManager.h>
#include <panda3d-webgl/load_prc_file.h>
#include <panda3d-webgl/cardMaker.h>
#include <panda3d-webgl/pandaNode.h>
#include <panda3d-webgl/nodePath.h>
#endif

using namespace astron;

void MyApp::run(std::string astron_addr)
{
    connect(astron_addr, (uint32_t)0x5d7939, "v0.0.0");
#ifdef HAVE_PANDA
    /* Add our Astron poll and window resize panda tasks */
    taskMgr->add(new GenericAsyncTask("Calls poll_datagram()", &astron_poll, this));
    taskMgr->add(new GenericAsyncTask("Resizes Panda Window", &resize_panda_window, this));
#else
    poll_forever(); // have the library create an emscripten main loop for you
#endif
}

#ifdef HAVE_PANDA
AsyncTask::DoneStatus MyApp::astron_poll(GenericAsyncTask *task, void *data)
{
    MyApp* app = static_cast<MyApp*>(data);
    app->poll_till_empty();
    return AsyncTask::DS_cont; // repeat next panda frame
}

/* The following Panda task is a hack to resize
 * the screen to the browser screen dimensions. */

AsyncTask::DoneStatus MyApp::resize_panda_window(GenericAsyncTask *task, void *data)
{
    const int frames = task->get_elapsed_frames();
    if (frames % 5 != 0) return AsyncTask::DS_cont; // only check every 5 frames

    MyApp* app = static_cast<MyApp*>(data);
    double b_width;
    double b_height;
    emscripten_get_element_css_size("canvas", &b_width, &b_height);

    if ((b_width != app->_win_width) || (b_height != app->_win_height))
    {
        app->_win_width = b_width;
        app->_win_height = b_height;

        WindowProperties winProps = WindowProperties();
        winProps.set_size(int(b_width), int(b_height));
        app->p_window->get_graphics_window()->request_properties(winProps);
    }
    return AsyncTask::DS_cont;
}
#endif // HAVE_PANDA


int main(int argc, char* argv[])
{
    /* Disable color output. Not supported on most browsers. (Only Chrome afaik) */
    g_logger->set_color_enabled(false);

    /* It is VITAL that you dynamically allocate `MyApp` via `new`.
     * If you allocate it on the stack, it will be cleared from memory as
     * soon as the emscripten main loop starts at `poll_forever()`.
     * You can allocate it on the stack if you call `poll_datagram()`
     * in your own loop that is in the scope where `MyApp` is defined.
     */
    MyApp *app = new MyApp();

#ifdef HAVE_PANDA
    // Load PRC engine configuration file
    load_prc_file("engine-config.prc");
    // Initialize Panda libraries
    init_libOpenALAudio();
    init_libpnmimagetypes();
    init_libwebgldisplay();

    // Open a new framework & window
    app->m_framework.open_framework(argc, argv);
    app->m_framework.set_window_title("Panda Window"); // not ported on webgl port yet
    app->p_window = app->m_framework.open_window();

    app->p_window->enable_keyboard(); // Enable keyboard detection
    app->p_window->setup_trackball(); // Enable default camera movement

    // create a quad to test
    CardMaker quad = CardMaker("card");
    quad.set_frame_fullscreen_quad();
    PT(PandaNode) quad_node = quad.generate(); // PT() equivalent of std::shared_ptr, but panda manages references

    // make a nodepath object for quad
    NodePath quad_np = NodePath(quad_node);
    quad_np.reparent_to(app->p_window->get_render());
#endif

    app->run("127.0.0.1:8080"); // websocket proxy on loop back interface (proxying to client agent)

#ifdef HAVE_PANDA
    // start the framework main loop
    app->m_framework.main_loop();
    app->m_framework.close_framework();
#endif
    return 0;
}