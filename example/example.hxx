/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file example.hxx
 * @author Max Rodriguez
 * @date 2023-06-05
 */

#ifndef ASTRON_LIBWASM_EXAMPLE_HXX
#define ASTRON_LIBWASM_EXAMPLE_HXX

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

#include "../src/client/ClientRepository.hxx"

namespace astron
{
class MyApp : public ClientRepository
{
  public:
    MyApp() {};
    void run(std::string astron_addr);

    /* Used at resize_panda_window() panda task */
    double _win_height = 0.0f;
    double _win_width = 0.0f;

#ifdef HAVE_PANDA
    PandaFramework m_framework;
    WindowFramework *p_window;
    NodePath camera;

    /* Our own NodePaths that represent the aspect2d
     * coordinates of different edges / corners of the window.
     */
    NodePath a2dTopCenter;
    NodePath a2dBottomCenter;
    NodePath a2dLeftCenter;
    NodePath a2dRightCenter;
    NodePath a2dTopLeft;
    NodePath a2dTopRight;
    NodePath a2dBottomLeft;
    NodePath a2dBottomRight;

    float a2dTop = 1.0f;
    float a2dBottom = -1.0f;
    float a2dLeft; // set to aspect ratio
    float a2dRight; // negative of aspect ratio

    static AsyncTask::DoneStatus astron_poll(GenericAsyncTask *task, void *data);
    static AsyncTask::DoneStatus resize_panda_window(GenericAsyncTask *task, void *data);
    static AsyncTask::DoneStatus update_a2d_nodes_to_aspect_ratio(GenericAsyncTask *task, void *data);
    static void gui_button_toggle_fullscreen_callback(const Event *ev, void *data);
#endif
};
}

#endif //ASTRON_LIBWASM_EXAMPLE_HXX