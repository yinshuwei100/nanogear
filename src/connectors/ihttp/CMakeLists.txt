include_directories(${CMAKE_SOURCE_DIR}/src/core)

add_library(NanogearIHTTPConnector
    nconnectionhandlerthread.cpp
    nhttpserver.cpp
)

set_target_properties(NanogearIHTTPConnector PROPERTIES
    VERSION ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}
    SOVERSION ${NANOGEAR_MAJOR}
)

target_link_libraries(NanogearIHTTPConnector Nanogear ${QT_LIBRARIES})