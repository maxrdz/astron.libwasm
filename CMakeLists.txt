cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(name astron.libwasm)
project(${name})
include_directories(src)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -fPIC")

# CMake Build Options
option(FORCE_COLORED_OUTPUT "Always produce ANSI-colored output (GNU/Clang only)." TRUE)

# Enable GCC/clang ANSI-colored terminal output using Ninja build tool
if (FORCE_COLORED_OUTPUT)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
        add_compile_options(-fdiagnostics-color=always)
    elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        add_compile_options(-fcolor-diagnostics)
    endif()
endif()