project(nanogear)
cmake_minimum_required(VERSION 2.6)

find_package(Boost 1.34 COMPONENTS
    program_options
    filesystem
    date_time
    REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(libs)
add_subdirectory(examples)
