project(nanogear)
cmake_minimum_required(VERSION 2.6)

# Test SUITE
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

find_package(Qt4)
set(QT_USE_QTNETWORK 1)
set(QT_DONT_USE_QTGUI 1)
include(${QT_USE_FILE})


add_subdirectory(lib)
add_subdirectory(examples)