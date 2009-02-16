set(nanogear_SRCS
    router.cpp
    server.cpp
    httpserver.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    httpserver.h
)

add_library(nanogear SHARED ${nanogear_SRCS})