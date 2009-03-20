set(nanogear_concrete_HTTP_SRCS
    HTTPServer.cpp
    ConnectionHandlerThread.cpp
)

qt4_wrap_cpp(nanogear_concrete_HTTP_SRCS
    HTTPServer.h
    ConnectionHandlerThread.h
)

add_library(nanogear_concrete_HTTP STATIC ${nanogear_concrete_HTTP_SRCS})
