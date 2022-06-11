
aux_source_directory(. SRC_LIST)
aux_source_directory(kidd SRC_LIST)
aux_source_directory(kidd/components/ SRC_LIST)
aux_source_directory(kidd/utils/gapbuffer SRC_LIST)
message(STATUS ${SRC_LIST})
include_directories(kidd)

message(STATUS ${SRC_LIST})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

add_executable(kidd ${SRC_LIST})
target_link_libraries(kidd ${CONAN_LIBS})
