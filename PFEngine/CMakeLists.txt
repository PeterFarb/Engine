# Works with 3.11 and tested through 3.18
cmake_minimum_required(VERSION 3.18)

# Project name and a few useful settings. Other commands can pick up the results
project(
  PFEngine
  VERSION 0.1
  DESCRIPTION "The PFE Engine"
  LANGUAGES CXX)

# Includes 
include(FetchContent)

# Configure GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

# Add External Dependencies
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
)

FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad
)
FetchContent_MakeAvailable(glfw)
FetchContent_MakeAvailable(glad)

# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/glfw")
# add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/extern/glad")
add_subdirectory("src")
