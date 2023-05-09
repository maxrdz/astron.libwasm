cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set(name astron.libwasm)
project(${name})
include_directories(src)

if (NOT EMSCRIPTEN)
    return() # Currently only building with Emscripten
endif()

if (WIN32) # Windows needs an extra define
    add_definitions(-D_WIN32_WINDOWS)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux") # Linux requires pthreads
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

if(NOT CMAKE_BUILD_TYPE) # Default to Debug
    message("Build Type not set. Defaulting to Debug...")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

set(CMAKE_CXX_STANDARD 11) # We need gnu+11 to compile with Boost.
set(CXX_STANDARD_REQUIRED ON)
if (DEFINED EMSCRIPTEN)
    set(CMAKE_CXX_COMPILER "em++") # Use Emscripten C++ compiler
    set(CMAKE_EXECUTABLE_SUFFIX ".wasm")
endif()

# ======================================
# ========== Compiler Flags ============
# ======================================

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sWASM=1 -sSTANDALONE_WASM=1 --no-entry")
# Ignore 'unused_xxx' warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

# Debug & Release compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -Oz")

# ======================================
# =========== CMake Options ============
# ======================================

# Use the Boost headers from emscripten-ports. Currently required.
option(USE_BOOST "Passes `-sUSE_BOOST_HEADERS=1` to the compiler & linker. Currently required." true)

# Enables compiling & linking to wasm64. This is currently experimental in Emscripten!
option(WASM64 "Passes `-sMEMORY64=1` to the compiler & linker. This is experimental! Default: false." false)

# Use 32-bit datagram length tags
option(USE_32BIT_DATAGRAMS "Datagrams and dclass fields will use 32-bit length tags instead of 16-bit." false)

# Use 128-bit channel IDs over the wire
option(USE_128BIT_CHANNELS "Compile with support for 128-bit channel IDs. Experimental." false)

if(USE_BOOST)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sUSE_BOOST_HEADERS=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sUSE_BOOST_HEADERS=1")
    add_definitions(-DBOOST_ASIO_HAS_PTHREADS) # Fixes "Only Windows and POSIX are supported!" error.
endif()
if(WASM64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sMEMORY64=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sMEMORY64=1")
endif()
if(USE_32BIT_DATAGRAMS)
    add_definitions(-DASTRON_32BIT_DATAGRAMS -DDCPARSER_32BIT_LENGTH_TAG)
endif()
if(USE_128BIT_CHANNELS)
    add_definitions(-DASTRON_128BIT_CHANNELS)
endif()

######### Define Core Components ########
set(UTIL_FILES
        src/util/Logger.cxx
)
set(DCPARSER_FILES
        src/dcparser/dcparser_composite1.cxx
        src/dcparser/dcparser_composite2.cxx
        src/dcparser/dcLexer.cxx
        src/dcparser/dcParser.cxx
)
set(NETWORK_FILES
        src/network/Connection.cxx
)
######### Internal Protocol Components #########
set(INTERNAL_FILES
        src/internal/InternalConnection.cxx
)
set(CORE_FILES
        ${UTIL_FILES} ${DCPARSER_FILES} ${NETWORK_FILES}
)
set(internal_build ${CORE_FILES} ${INTERNAL_FILES})
add_library(astron STATIC ${internal_build})

######### Example WASM Binaries #########
add_subdirectory(example)