
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE}/lib)

add_library("${PROJECT_NAME}" "")
add_library(Engine::Engine ALIAS "${PROJECT_NAME}")


target_link_libraries("${PROJECT_NAME}" "glad")
target_link_libraries("${PROJECT_NAME}" "glfw")


# set_target_properties(Engine PROPERTIES PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/src/first.hpp")
target_include_directories("${PROJECT_NAME}" PUBLIC
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>" #foo_export.h
	"$<INSTALL_INTERFACE:include>" #${CMAKE_INSTALL_PREFIX}/include
)

if(NOT BUILD_SHARED_LIBS)
	set(STATIC_POSTFIX "-s")
	set_target_properties("${PROJECT_NAME}" PROPERTIES 
	COMPILE_FLAGS -DFOO_STATIC_DEFINE)
endif()

#Rename target Foo
set_target_properties("${PROJECT_NAME}" PROPERTIES
	DEBUG_POSTFIX "${STATIC_POSTFIX}-d" 
	RELEASE_POSTFIX "${STATIC_POSTFIX}"
	MINSIZEREL_POSTFIX "${STATIC_POSTFIX}-mr"
	RELWITHDEBINFO_POSTFIX "${STATIC_POSTFIX}-rd"
)

# include("GenerateExportHeader")
# generate_export_header("${PROJECT_NAME}")
# install(FILES "${CMAKE_CURRENT_BINARY_DIR}/engine_export.h" DESTINATION "include")


add_subdirectory("include")
add_subdirectory("src")
