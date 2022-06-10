cmake_minimum_required(VERSION 3.15)
project(kidd)

include(${CMAKE_BINARY_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src/)

