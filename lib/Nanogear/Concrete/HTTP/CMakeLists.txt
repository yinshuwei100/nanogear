set(nanogear_concrete_HTTP_SRCS
    ConnectionHandlerThread.cpp
    ThreadedHTTPServer.cpp
)

qt4_wrap_cpp(nanogear_concrete_HTTP_SRCS
    HTTPServer.h
    ThreadedHTTPServer.h
    ConnectionHandlerThread.h
)

add_library(nanogear_concrete_HTTP STATIC ${nanogear_concrete_HTTP_SRCS})
