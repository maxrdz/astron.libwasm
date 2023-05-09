######### Example WASM Binaries #########
set(INTERNAL_EXAMPLE_SOURCE
        internal-example.cxx
)
add_executable(internal_example ${INTERNAL_EXAMPLE_SOURCE})
target_link_libraries(internal_example PUBLIC astron)