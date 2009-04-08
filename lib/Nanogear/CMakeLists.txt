add_subdirectory(Concrete)
add_subdirectory(Resource)

set(nanogear_SRCS
    MimeType.cpp
    Application.cpp
    Status.cpp
    Router.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    Status.h
    Method.h
)

add_library(nanogear SHARED ${nanogear_SRCS})
target_link_libraries(nanogear nanogear_concrete_HTTP nanogear_resource)
