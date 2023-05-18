# Overwrite CXX flags / linker flags for this directory
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-sWASM=1")

if(${CMAKE_BUILD_TYPE} MATCHES "Debug")
    # Compile & link with Clang's undefined behavior sanitized (UBSan)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=undefined")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=undefined -sSAFE_HEAP=1")
endif()

# Ignore 'unused_xxx' warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -gsource-map")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -Oz")

######### Example WASM Binaries #########
add_executable(example example.cxx)
target_link_libraries(example PUBLIC astron)