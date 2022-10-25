cmake_minimum_required (VERSION 3.5)

project(Sandbox)

set(SANDBOX_SOURCE_DIR src/)
set(SANDBOX_INCLUDE_DIR src/)

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

file(GLOB_RECURSE SANDBOX_SOURCE_FILES ${SANDBOX_SOURCE_DIR}/*.cpp)

set(SANDBOX_SOURCE_FILES_MANUAL
    ${SANDBOX_SOURCE_DIR}/Sandbox.cpp

    ${SANDBOX_SOURCE_DIR}/Scenes/TestScene.cpp
)

set(SANDBOX_INCLUDE_FILES_MANUAL
	${SANDBOX_SOURCE_DIR}/Sandbox.hpp

    ${SANDBOX_SOURCE_DIR}/Scenes/TestScene.hpp
)

add_executable(${PROJECT_NAME} ${SANDBOX_SOURCE_FILES} ${SANDBOX_INCLUDE_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${SANDBOX_INCLUDE_DIR}/)

target_link_libraries(${PROJECT_NAME} PUBLIC Farfocel)

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

# on windows, when using dynamic SFML libs, copy all the .dlls (excluding openal.dll) to Sandbox's bin folder.
if(WIN32 AND BUILD_SHARED_LIBS)
	add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> $<TARGET_FILE_DIR:${PROJECT_NAME}> COMMAND_EXPAND_LISTS)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Sandbox-Binary/)
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Sandbox-Binary/Debug)
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Sandbox-Binary/Release)

install(TARGETS ${PROJECT_NAME})
