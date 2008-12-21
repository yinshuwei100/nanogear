# tests

enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/libs/rest_api)

# Method test
add_executable(method method.cpp)
target_link_libraries(method nanogear_rest boost_regex-mt)
add_test(method ${CMAKE_CURRENT_BINARY_DIR}/method)

# Media Type test
add_executable(media_type media_type.cpp)
target_link_libraries(media_type nanogear_rest boost_regex-mt)
add_test(media_type ${CMAKE_CURRENT_BINARY_DIR}/media_type)

