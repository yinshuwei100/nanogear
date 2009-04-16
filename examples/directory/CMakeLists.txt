include_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(directory main.cpp)
target_link_libraries(directory Nanogear ${QT_LIBRARIES})

