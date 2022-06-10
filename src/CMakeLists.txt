set(SRC_LIST main.cpp)
aux_source_directory(kidd SRC_LIST)
include_directories(kidd)

message(STATUS ${SRC_LIST})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(kidd ${SRC_LIST})
target_link_libraries(kidd ${CONAN_LIBS})
