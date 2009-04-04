set(nanogear_concrete_HTTP_SRCS
    HTTPServer.cpp
    ConnectionHandlerThread.cpp
)

add_library(nanogear_concrete_HTTP STATIC ${nanogear_concrete_HTTP_SRCS})
