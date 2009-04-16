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

add_library(Nanogear SHARED ${nanogear_SRCS})
set_target_properties(Nanogear PROPERTIES
    VERSION ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}
    SOVERSION ${NANOGEAR_MAJOR}
)
target_link_libraries(Nanogear ${QT_LIBRARIES})