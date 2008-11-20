# tests

#enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/libs/rest_api)

add_executable(uri_template uri_template.cpp)
target_link_libraries(uri_template nanogear_rest)
#add_test(uri_template_test ${CMAKE_CURRENT_BINARY_DIR}/uri_template)