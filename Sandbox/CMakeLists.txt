cmake_minimum_required (VERSION 3.5)

project(Sandbox)

set(SANDBOX_SOURCE_DIR src/)
set(SANDBOX_INCLUDE_DIR src/)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Sandbox-Binary/Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Sandbox-Binary/Release)
endif()

file(GLOB_RECURSE SANDBOX_SOURCE_FILES ${SANDBOX_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SANDBOX_SOURCE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SANDBOX_INCLUDE_DIR}/)

target_link_libraries(${PROJECT_NAME} PUBLIC Farfocel)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

# on windows, when using dynamic SFML libs, copy all the .dlls (excluding openal.dll) to Sandbox's bin folder.
if(WIN32 AND BUILD_SHARED_LIBS)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS ${PROJECT_NAME})
