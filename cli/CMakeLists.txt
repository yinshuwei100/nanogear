add_executable(nanogear
    main.cpp
    generate_project.cpp
    utils.cpp)

target_link_libraries(nanogear 
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_PROGRAM_OPTIONS_LIBRARY})

