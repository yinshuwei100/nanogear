add_subdirectory(Concrete)
add_subdirectory(Resource)

set(nanogear_SRCS
    Router.cpp
    Server.cpp
)

add_library(nanogear SHARED ${nanogear_SRCS})
target_link_libraries(nanogear nanogear_concrete_HTTP)