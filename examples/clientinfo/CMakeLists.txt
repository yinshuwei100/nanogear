include_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(clientinfo main.cpp)
target_link_libraries(clientinfo nanogear ${QT_LIBRARIES})
