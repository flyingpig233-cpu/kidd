cmake_minimum_required(VERSION 3.15)
project(kidd)

add_compile_definitions(UNICODE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src/)
