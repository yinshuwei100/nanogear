# tests

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/libs/rest_api)

add_executable(method method.cpp)
add_executable(uri_template uri_template.cpp)
add_executable(media_type media_type.cpp)
target_link_libraries(uri_template nanogear_rest boost_regex-mt)
target_link_libraries(method nanogear_rest boost_regex-mt)
target_link_libraries(media_type nanogear_rest boost_regex-mt)
add_test(uri_template_test ${CMAKE_CURRENT_BINARY_DIR}/uri_template)
add_test(method_test ${CMAKE_CURRENT_BINARY_DIR}/method)
add_test(media_type_test ${CMAKE_CURRENT_BINARY_DIR}/media_type)

