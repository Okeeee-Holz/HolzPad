# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.24.0)
set(CMAKE_OSX_DEPLOYMENT_TARGET "14.3" CACHE STRING "Minimum OS X deployment version")

project (HolzPadToolchain)


# project options
option(BUILD_STATIC "Build libraries statically" ON)
if (BUILD_STATIC)
	option(BUILD_SHARED_LIBS "Build all 3rd party libraries as shared" OFF)
else ()
	option(BUILD_SHARED_LIBS "Build all 3rd party libraries as shared" ON)
endif()


# apple compiler path
if (APPLE)
	set( CMAKE_CXX_COMPILER "/usr/bin/clang++" )
	set( CMAKE_C_COMPILER "/usr/bin/clang" )
endif()


# 3rd party library path
set(LIBRARY_PATH ${CMAKE_SOURCE_DIR}/3rdParty)


# set global options
set(CMAKE_CXX_STANDARD 23)

# Include sub-projects.
add_subdirectory ("3rdParty")
add_subdirectory ("HolzPad")
