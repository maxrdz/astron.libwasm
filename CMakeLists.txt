cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(name astron.libwasm)
project(${name})
include_directories(src)

if (NOT EMSCRIPTEN)
    return() # Currently only building with Emscripten
endif()

set(CMAKE_CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED ON)
if (DEFINED EMSCRIPTEN)
    set(CMAKE_CXX_COMPILER "em++") # Use Emscripten C++ compiler
    set(CMAKE_EXECUTABLE_SUFFIX ".wasm")
endif()

# Default compiler / linker flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sWASM=1 -sSTANDALONE_WASM=1 --no-entry")

# ======================================
# =========== CMake Options ============
# ======================================

# Enables compiling & linking to wasm64. This is currently experimental in Emscripten!
option(WASM64 "Passes `-sMEMORY64=1` to the compiler & linker. This is experimental! Default: false." false)

# Check options values & apply
if(WASM64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sMEMORY64=1") # wasm64
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sMEMORY64=1")
endif()

# ==================================================
# ======== Dynamic Compiler & Linker Flags =========
# ==================================================

if(NOT CMAKE_BUILD_TYPE)
    message("Build Type not set. Defaulting to Debug...")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE EQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g3") # Set compiler flags for debugging
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g0 -Oz -flto") # Set optimization compiler flags
endif()

# DC Parser library
set(dcparser_src src/dcparser/p3dcparser_composite1.cxx
    src/dcparser/p3dcparser_composite2.cxx
    src/dcparser/dcLexer.cxx src/dcparser/dcParser.cxx)
add_executable(dcparser ${dcparser_src})

# astron.libwasm library
set(internal src/main.cxx)
add_executable(libastron ${internal})
