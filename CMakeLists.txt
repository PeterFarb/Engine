cmake_minimum_required(VERSION 3.0.0)

#Set target ouput directory
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/bin")

set(VALID_BUILD_TYPES "Release" "Debug" "MinSizeRel" "RelWithDebInfo")

option(BUILD_SHARED_LIBS "True when building a shared library" False)

project(Engine)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")




#set CMAKE_BUILD_TYPE default value
if(NOT CMAKE_CONFIGURATION_TYPES)
    if("${CMAKE_BUILD_TYPE}" STREQUAL "")
        set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Build configuration" FORCE)
    endif()
endif()

#validate CMAKE_BUILD_TYPE
if(NOT CMAKE_CONFIGURATION_TYPES)
    list(FIND VALID_BUILD_TYPES "${CMAKE_BUILD_TYPE}" INDEX)
    if(${INDEX} MATCHES -1)
        message(FATAL_ERROR "Invalid build type. Valid types are [${VALID_BUILD_TYPES}]")
    endif()
endif()

#Create dropdown list for CMake gui
if(NOT CMAKE_CONFIGURATION_TYPES)
    if(DEFINED CMAKE_BUILD_TYPE)
        set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS ${VALID_BUILD_TYPES})
    endif()
endif()


add_subdirectory(engine)
add_subdirectory(game)


# # Source files
set(LIB_DIR "${PROJECT_SOURCE_DIR}/lib")

# GLFW
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${LIB_DIR}/glfw")
target_compile_definitions(${PROJECT_NAME} PRIVATE "GLFW_INCLUDE_NONE")

# glad
set(GLAD_DIR "${LIB_DIR}/glad")
add_subdirectory("${LIB_DIR}/glad")

