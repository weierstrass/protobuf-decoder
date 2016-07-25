cmake_minimum_required (VERSION 2.8)

project (protobuf-decoder)

set (CMAKE_CXX_STANDARD 11)
#set(CMAKE_BUILD_TYPE Release)

add_subdirectory (src) 

add_subdirectory (test)
enable_testing ()

add_test (NAME MyTest COMMAND protobuf-decoder_test)
