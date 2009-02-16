include_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(simple main.cpp)
target_link_libraries(simple nanogear ${QT_LIBRARIES})
