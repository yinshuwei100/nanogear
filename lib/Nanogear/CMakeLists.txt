set(nanogear_SRCS
    MimeType.cpp
    Application.cpp
    Status.cpp
    Router.cpp
    Method.cpp

    Resource/Resource.cpp
    Resource/Representation.cpp
    Resource/Directory.cpp

    Concrete/HTTP/HTTPServer.cpp
    Concrete/HTTP/ConnectionHandlerThread.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    Status.h
    Method.h
)

add_library(nanogear SHARED ${nanogear_SRCS})
target_link_libraries(nanogear ${QT_LIBRARIES})