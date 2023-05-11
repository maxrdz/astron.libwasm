set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_EXE_LINKER_FLAGS "-sWASM=1 -sSTANDALONE_WASM=1")
# Ignore 'unused_xxx' warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g3")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -g0 -Oz")

######### Example WASM Binaries #########
set(INTERNAL_EXAMPLE_SOURCE
        internal-example.cxx
)
add_executable(internal_example ${INTERNAL_EXAMPLE_SOURCE})
target_link_libraries(internal_example PUBLIC astron-internal)