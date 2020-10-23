# Note that headers are optional, and do not affect add_library, but they will not
# show up in IDEs unless they are listed in add_library.

# Optionally glob, but only for CMake 3.12 or later:
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}/*.h")
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library("${PROJECT_NAME}" ${SOURCE_LIST} ${HEADER_LIST})
add_library("${PROJECT_NAME}::${PROJECT_NAME}" ALIAS "${PROJECT_NAME}")


# Set To Build Static Lib
if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DFOO_STATIC_DEFINE)
endif()

# Rename Target Based on POSTFIX
set_target_properties("${PROJECT_NAME}" PROPERTIES
	DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
	RELEASE_POSTFIX "${STATIC_POSTFIX}"
	MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
	RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)

# # # We need this directory, and users of our library will need it too
target_include_directories("${PROJECT_NAME}" PUBLIC ../include)

# # This depends on (header only) boost
target_link_libraries("${PROJECT_NAME}" "glad" "glfw")

# All users of this library will need at least C++11
target_compile_features("${PROJECT_NAME}" PUBLIC cxx_std_11)
target_compile_definitions("${PROJECT_NAME}" PRIVATE "GLFW_INCLUDE_NONE")

