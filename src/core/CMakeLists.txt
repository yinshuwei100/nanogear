set(nanogear_SRCS
    ndirectoryresource.cpp
    nmethod.cpp
    nrepresentation.cpp
    nresource.cpp
    nrouter.cpp
    nstatus.cpp
    nmimetype.cpp
)

qt4_wrap_cpp(nanogear_SRCS
    nstatus.h
    nmethod.h
)

add_library(Nanogear SHARED ${nanogear_SRCS})

set_target_properties(Nanogear PROPERTIES
    VERSION ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}
    SOVERSION ${NANOGEAR_MAJOR}
)

target_link_libraries(Nanogear magic ${QT_LIBRARIES})
