cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(name astron.libwasm)
project(${name})
include_directories(src)

if (NOT EMSCRIPTEN)
    return() # Only building with Emscripten
endif()

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "em++") # Use Emscripten C++ compiler

# compiler flags / linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sWASM=1") # TODO: add '--no-entry'

if(NOT CMAKE_BUILD_TYPE) # Default to Debug build type
    message("Build Type not set, defaulting to Debug...")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE EQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3") # Set compiler flags for debugging
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0 -Oz -flto") # Set optimization compiler flags
endif()

set(sources "src/main.cxx")
add_executable(libastron ${sources})
