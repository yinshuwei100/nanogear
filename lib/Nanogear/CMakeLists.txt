add_subdirectory(Concrete)
add_subdirectory(Resource)

set(nanogear_SRCS
    MimeType.cpp
    Application.cpp
    Method.cpp
    Status.cpp
    Request.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    Application.h
    Status.h
    Method.h
)

add_library(nanogear SHARED ${nanogear_SRCS})
target_link_libraries(nanogear nanogear_concrete_HTTP nanogear_resource)
