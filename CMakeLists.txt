cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set(name astron.libwasm)
project(${name})
include_directories(src)

if (NOT EMSCRIPTEN)
    return() # Currently only building with Emscripten
endif()

if (WIN32) # Windows needs an extra define
    add_compile_definitions(_WIN32_WINDOWS)
endif()

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux") # Linux requires pthreads
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()

if(NOT CMAKE_BUILD_TYPE) # Default to Debug
    message("Build Type not set. Defaulting to Debug...")
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 11) # We need gnu+11 to compile with Boost.
set(CXX_STANDARD_REQUIRED ON)

# ======================================
# =========== CMake Options ============
# ======================================

# Use the Boost headers from emscripten-ports. Was previously required, now it's not used.
option(USE_BOOST "Passes `-sUSE_BOOST_HEADERS=1` to the compiler & linker." false)

# Enables compiling & linking to wasm64. This is currently experimental in Emscripten!
option(WASM64 "Passes `-sMEMORY64=1` to the compiler & linker. This is experimental! Default: false." false)

# Use 32-bit datagram length tags
option(USE_32BIT_DATAGRAMS "Datagrams and dclass fields will use 32-bit length tags instead of 16-bit." false)

# Use 128-bit channel IDs over the wire
option(USE_128BIT_CHANNELS "Compile with support for 128-bit channel IDs. Experimental." false)

# Build example WASM binaries with static library
option(BUILD_EXAMPLE "Builds the example WASM binaries along with the static library." true)

# ===============================================
# ========== Compiler / Linker Flags ============
# ===============================================

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lwebsocket.js -sWASM=1 --no-entry")
# Ignore 'unused_xxx' warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

if(USE_BOOST)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sUSE_BOOST_HEADERS=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sUSE_BOOST_HEADERS=1")
    add_compile_definitions(BOOST_ASIO_HAS_PTHREADS) # Fixes "Only Windows and POSIX are supported!" error.
endif()
if(WASM64)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -sMEMORY64=1")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sMEMORY64=1")
endif()
if(USE_32BIT_DATAGRAMS)
    add_compile_definitions(ASTRON_32BIT_DATAGRAMS DCPARSER_32BIT_LENGTH_TAG)
endif()
if(USE_128BIT_CHANNELS)
    add_compile_definitions(ASTRON_128BIT_CHANNELS)
endif()

# ==============================================
# =========== Debug / Release flags ============
# ==============================================

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -gsource-map") # -g4 deprecated
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -sASSERTIONS=2 -sSTACK_OVERFLOW_CHECK=1 --emrun")

    # Compile & link with Clang's undefined behavior and address sanitizers (UBSan & ASan)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined -fsanitize=address")

    add_compile_definitions(ASTRON_DEBUG_MESSAGES) # enable astron logger debug output
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -Oz")
endif()

# ===============================================
# ========== Define Source Components ===========
# ===============================================

set(SOURCE_FILES
        # util
        src/util/Logger.cxx
        # dc file
        src/dcfile/dcparser_composite1.cxx
        src/dcfile/dcparser_composite2.cxx
        src/dcfile/dcLexer.cxx
        src/dcfile/dcParser.cxx
        # network
        src/network/Connection.cxx
        # object
        src/object/DistributedObject.cxx
        src/object/ObjectFactory.cxx
        src/object/ObjectRepository.cxx
        # client
        src/client/ClientConnection.cxx
)
add_library(astron STATIC ${SOURCE_FILES}) # builds libastron.a

if(BUILD_EXAMPLE) # build example WASM binaries
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # Output Emscripten's HTML wrapper
    add_subdirectory(example)
endif()