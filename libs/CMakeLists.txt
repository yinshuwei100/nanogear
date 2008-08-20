add_subdirectory(rest)

file(GLOB_RECURSE rest_lib_sources ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")
add_library(nanogear_rest SHARED ${rest_lib_sources})