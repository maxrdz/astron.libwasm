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
NodePath camera;
#endif

#include "../src/client/ClientRepository.hxx"

namespace astron
{
class MyReactor : public ClientRepository
{
  public:
    MyReactor() {};
    void run(std::string astron_addr);

  private:
#ifdef HAVE_PANDA // define AstronPoll panda task
    static AsyncTask::DoneStatus astron_poll(GenericAsyncTask *task, void *data);
#endif
};
}

#endif //ASTRON_LIBWASM_EXAMPLE_HXX