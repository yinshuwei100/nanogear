project(nanogear CXX C)
cmake_minimum_required(VERSION 2.6)
include("VERSION.cmake")
message(STATUS "This is Nanogear ${NANOGEAR_MAJOR}.${NANOGEAR_MINOR}.${NANOGEAR_PATCH}")


# Test suite
if (${ENABLE_TESTS})
    include(CTest)
    enable_testing()
    set(CTEST_PROJECT_NAME "Nanogear")
    set(CTEST_NIGHTLY_START_TIME "23:00:00 GMT")
    set(CTEST_DROP_METHOD http)
    set(CTEST_DROP_SITE "dashboard.binaryhelix.net")
    set(CTEST_DROP_LOCATION "/submit.php?project=Nanogear")
    set(CTEST_DROP_SITE_CDASH TRUE)
endif(${ENABLE_TESTS})
#####


# Documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
    message(STATUS "Building documentation")
    add_subdirectory(docs)
endif (DOXYGEN_FOUND)


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


# Build the examples?
if (${BUILD_EXAMPLES})
    message(STATUS "Will build examples")
    add_subdirectory(examples)
endif(${BUILD_EXAMPLES})


# Build the library
add_subdirectory(lib)
