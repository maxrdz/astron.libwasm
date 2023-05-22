# Overwrite CXX flags / linker flags for this directory
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-sWASM=1 -lwebsocket.js")

if(USE_PANDA) # if USE_PANDA=1, link with the Panda3D webgl-port static librarys
    # NOTE: All panda static libraries (.a / .lib) should be under the `example/` directory.
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L${CMAKE_CURRENT_SOURCE_DIR} -L/usr/local/lib")
    # Assuming you built Panda with the following dependencies: ZLib, Vorbis, FreeType (static libraries)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lz -lp3framework -lpanda -lpandaexpress")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -lp3dtoolconfig -lp3dtool -lp3openal_audio -lp3direct")
    # Path to Panda3D system header files
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include/")
    add_compile_definitions(HAVE_PANDA)
endif()

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    # Compile & link with Clang's undefined behavior and address sanitizers (UBSan & ASan)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined -fsanitize=address")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined -fsanitize=address")
endif()

# Ignore 'unused_xxx' warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -gsource-map")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -Oz")

######### Example WASM Binaries #########
add_executable(example example.cxx)
target_link_libraries(example PUBLIC astron)