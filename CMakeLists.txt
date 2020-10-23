cmake_minimum_required(VERSION 3.18)

# Project name and a few useful settings. Other commands can pick up the results
project(
  PFE
  VERSION 0.1
  DESCRIPTION "A OpenGl Engine/Game Project Meant For Learning."
  LANGUAGES CXX)

# Only do these if this is the main project, and not if it is included through add_subdirectory
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)

    # Set target ouput directory
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin")

    # Let's ensure -std=c++xx instead of -std=g++xx
    set(CMAKE_CXX_EXTENSIONS OFF)
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

endif()

# CMake gui
option(BUILD_SHARED_LIBS "True when building a shared library" True)
set(VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")
if(NOT CMAKE_CONFIGURATION_TYPES)
    if(DEFINED CMAKE_BUILD_TYPE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${VALID_BUILD_TYPES})
    endif()
endif()

# Add subdirectories
add_subdirectory(PFEngine)
add_subdirectory(Sandbox)