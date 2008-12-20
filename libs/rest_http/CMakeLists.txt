include_directories(
${CMAKE_CURRENT_SOURCE_DIR}/../rest_api
${CMAKE_CURRENT_SOURCE_DIR}/../http)
add_library(nanogear_rest_http SHARED
    nanogear/rest/http/response.cpp
    nanogear/rest/http/engine.cpp
)
