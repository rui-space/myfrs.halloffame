cmake_minimum_required(VERSION 3.5)

include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories (${PROTOBUF_INCLUDE_DIR})

protobuf_generate_cpp (ProtoSources ProtoHeaders
	Common.proto)

add_library (messageProto STATIC ${ProtoSources} ${ProtoHeaders})

# add include directories to a target (library or executable)
message (CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories (messageProto PUBLIC ${CMAKE_CURRENT_BINARY_DIR}../include/)
