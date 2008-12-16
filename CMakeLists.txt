project(nanogear)

# Testing
enable_testing()
set(CTEST_PROJECT_NAME "Nanogear")
set(CTEST_NIGHTLY_START_TIME "23:00:00 GMT")
set(CTEST_DROP_METHOD http)
set(CTEST_DROP_SITE "dashboard.binaryhelix.net")
set(CTEST_DROP_LOCATION "/submit.php?project=Nanogear")
set(CTEST_DROP_SITE_CDASH TRUE)

cmake_minimum_required(VERSION 2.6)

find_package(Boost 1.34 COMPONENTS
    program_options
    filesystem
    date_time
    REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(libs)
add_subdirectory(examples)
