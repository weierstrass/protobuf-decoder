
# set up google test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# set up gtkmm 3.0
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-3.0)

link_directories(
    ${GTKMM_LIBRARY_DIRS}  )

include_directories(
    ${GTKMM_INCLUDE_DIRS}  )

# include all source files recursively
file(GLOB_RECURSE SRC_FILES src/*.cpp ../src/conversion/*.cpp)

# define executable to build from source files
add_executable(protobuf-decoder_test ${SRC_FILES})

# link executable with libraries
target_link_libraries(protobuf-decoder_test
    ${GTKMM_LIBRARIES}
    ${GTEST_BOTH_LIBRARIES} )
