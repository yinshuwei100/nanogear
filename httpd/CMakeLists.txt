set(httpd_SRCS
    qhttpserver.cpp
)

qt4_wrap_cpp(httpd_moc_SRCS qhttpserver.h)

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${QT_QTNETWORK_INCLUDE_DIR})
add_library(httpd SHARED ${httpd_SRCS} ${httpd_moc_SRCS})
target_link_libraries(httpd ${QT_LIBRARIES})