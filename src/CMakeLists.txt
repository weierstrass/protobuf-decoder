
# set up gtkmm 3.0
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

# set up protobuf
include(FindProtobuf)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})
#message(${PROTOBUF_INCLUDE_DIRS})

# BOOST
find_package(Boost COMPONENTS system filesystem REQUIRED)

# include all source files recursively
file(GLOB_RECURSE SRC_FILES ./*.cpp)

# define executable to build from source files
if(APPLE)
  add_executable(protobuf-decoder MACOSX_BUNDLE ${SRC_FILES})
else()
  add_executable(protobuf-decoder ${SRC_FILES})
endif()

# link executable with libraries
target_link_libraries(protobuf-decoder
    ${GTKMM_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
)

# bundle creation
if(APPLE)
    add_definitions(-DAPPLE_BUNDLE)
    set(GUI_TYPE MACOSX_BUNDLE)

    # create Info.plist file
    #set(MACOSX_BUNDLE_ICON_FILE qterminal.icns)
    set(MACOSX_BUNDLE_INFO_STRING "protobuf-decoder ${STR_VERSION}")
    set(MACOSX_BUNDLE_GUI_IDENTIFIER "com.protobuf-decoder")
    set(MACOSX_BUNDLE_LONG_VERSION_STRING "${STR_VERSION}")
    set(MACOSX_BUNDLE_BUNDLE_NAME "protobuf-decoder")
    set(MACOSX_BUNDLE_SHORT_VERSION_STRING "${STR_VERSION}")
    set(MACOSX_BUNDLE_BUNDLE_VERSION "${STR_VERSION}")
    set(MACOSX_BUNDLE_COPYRIGHT "(c) Andreas Bülling")

    set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/src)

    INSTALL(TARGETS protobuf-decoder DESTINATION "${CMAKE_INSTALL_PREFIX}" )

    install(CODE "include(BundleUtilities)
                  set(BU_CHMOD_BUNDLE_ITEMS TRUE)
                  fixup_bundle(\"${CMAKE_INSTALL_PREFIX}/protobuf-decoder.app\" \"\" \"\")"
            COMPONENT Runtime)
else()

    INSTALL(TARGETS protobuf-decoder DESTINATION "${CMAKE_INSTALL_PREFIX}" )

endif()

