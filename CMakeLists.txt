project(nanogear)
cmake_minimum_required(VERSION 2.4)

find_package(Boost 1.35 COMPONENTS
    program_options
    filesystem
    REQUIRED)

include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(cli)
add_subdirectory(libs)
