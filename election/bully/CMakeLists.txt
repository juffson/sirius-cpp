cmake_minimum_required(VERSION 3.20.0)
project(sirius-election-bully)
set(CMAKE_CXX_STANDARD 17)
include_directories(${PROTOBUF_INCLUDE_DIRS})
find_package(Protobuf REQUIRED)
# generate pb files
set(BULLY_PROTOCOL_DIR "${CMAKE_CURRENT_SOURCE_DIR}/protos")
FILE(GLOB_RECURSE BULLY_PROTOCOL_FILES ${BULLY_PROTOCOL_DIR}/*.proto)
foreach(ProtoFile ${BULLY_PROTOCOL_FILES})
    execute_process(COMMAND protoc --cpp_out=${CMAKE_CURRENT_BINARY_DIR} -I ${BULLY_PROTOCOL_DIR} ${ProtoFile} WORKING_DIRECTORY ${BULLY_PROTOCOL_DIR})
endforeach()

aux_source_directory(src SRC)
add_library(bully ${SRC})
