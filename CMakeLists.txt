cmake_minimum_required(VERSION 3.15)
project(kidd)

include(${CMAKE_BINARY_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} src/main.cpp)

message(STATUS ${CONAN_LIBS})

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
