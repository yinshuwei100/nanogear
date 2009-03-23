add_subdirectory(Concrete)
add_subdirectory(Resource)

set(nanogear_SRCS
    Context.cpp
    Resource/Resource.cpp
    Resource/Representation.cpp
    MimeType.cpp
    Application.cpp
    Method.cpp
    Status.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    Resource/Resource.h
    Application.h
    Server.h
    Method.h
    Status.h
)

add_library(nanogear SHARED ${nanogear_SRCS})
target_link_libraries(nanogear nanogear_concrete_HTTP)
