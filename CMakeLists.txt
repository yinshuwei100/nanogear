project(nanogear CXX C)
cmake_minimum_required(VERSION 2.6)
include("VERSION.cmake")
message(STATUS "This is Nanogear ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}")

# Documentation
find_package(Doxygen)
if (DOXYGEN_FOUND AND DOT_FOUND)
    message(STATUS "Building documentation")
    add_subdirectory(docs)
endif (DOXYGEN_FOUND AND DOT_FOUND)

find_package(Qt4 REQUIRED)
set(QT_USE_QTNETWORK 1)
set(QT_DONT_USE_QTGUI 1)
include(${QT_USE_FILE})


# Be strict?
if (${PEDANTIC})
    message(STATUS "Pedantic mode enabled")
    add_definitions(-Wall)
    add_definitions(-pedantic)
else (${PEDANTIC})
    message(STATUS "Pedantic mode is NOT enabled")
    message(STATUS "  If you are a developer you are strongly encouraged to activate")
    message(STATUS "  the pedantic mode")
endif (${PEDANTIC})

add_subdirectory(examples)
add_subdirectory(src)
