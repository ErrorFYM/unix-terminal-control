cmake_minimum_required(VERSION 3.10)

project(Unix_Terminal_Control)

# file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # set output directory for .a and .lib
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # set output directory for .so and .dll
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # set output directory for executables (.exe)

add_library(Unix_Terminal_Control ${CMAKE_CURRENT_SOURCE_DIR}/src/unix_terminal_control.c)
target_include_directories(Unix_Terminal_Control PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
