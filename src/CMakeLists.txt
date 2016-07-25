
# set up gtkmm 3.0
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

# set up protobuf
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

# BOOST
find_package(Boost COMPONENTS system filesystem REQUIRED)

# include all source files recursively
file(GLOB_RECURSE SRC_FILES ./*.cpp)

# define executable to build from source files
add_executable(protobuf-decoder ${SRC_FILES})

# link executable with libraries
target_link_libraries(protobuf-decoder
    ${GTKMM_LIBRARIES}
    ${PROTOBUF_LIBRARIES}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
)
    
