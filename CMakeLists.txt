cmake_minimum_required (VERSION 2.8)

project (protobuf-decoder)

set (CMAKE_CXX_STANDARD_REQUIRED 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#set(CMAKE_BUILD_TYPE Release)
set(STR_VERSION "0.1.0")

set(CPACK_BUNDLE_NAME "protobuf-decoder")
set(CPACK_BUNDLE_STARTUP_COMMAND src/protobuf-decoder)
set(CPACK_BUNDLE_PLIST "osx_deploy/Info.plist")
set(CPACK_BUNDLE_ICON "osx_deploy/icon.icns")

add_subdirectory (src) 

add_subdirectory (test)
enable_testing ()

add_test (NAME MyTest COMMAND protobuf-decoder_test)

INCLUDE(CPack)
