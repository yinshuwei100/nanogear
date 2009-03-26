set(nanogear_resource_SRCS
    Representation.cpp
    Resource.cpp
)

qt4_wrap_cpp(nanogear_resource_SRCS
    Resource.h
)

add_library(nanogear_resource STATIC ${nanogear_resource_SRCS})