include_directories(${CMAKE_SOURCE_DIR}/lib)
add_executable(forms main.cpp)
target_link_libraries(forms Nanogear ${QT_LIBRARIES})
