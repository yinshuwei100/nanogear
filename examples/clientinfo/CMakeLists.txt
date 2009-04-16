include_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(clientinfo main.cpp)
target_link_libraries(clientinfo Nanogear ${QT_LIBRARIES})
