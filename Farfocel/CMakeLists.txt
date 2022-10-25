cmake_minimum_required (VERSION 3.5)

project(Farfocel)

# Static SFML libs are currently only possible on Windows, as we compile them ourselfs. On Linux this project uses only dynamic SFML libs
if(WIN32)
    # Fetch the SFML v2.5.1 GitHub project.
    include(FetchContent)
    FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
    FetchContent_MakeAvailable(SFML)
endif()

set(FARFOCEL_SOURCE_DIR src/)
set(FARFOCEL_INCLUDE_DIR include/)

set(CMAKE_DEBUG_POSTFIX "-d")

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

file(GLOB_RECURSE FARFOCEL_SOURCE_FILES ${FARFOCEL_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FARFOCEL_INCLUDE_FILES ${FARFOCEL_INCLUDE_DIR}/*.hpp)

set(FARFOCEL_SOURCE_FILES_MANUAL
    ${FARFOCEL_SOURCE_DIR}/Core/Runtime.cpp

    ${FARFOCEL_SOURCE_DIR}/Scene/SceneManager.cpp

    ${FARFOCEL_SOURCE_DIR}/Resource/ResourceManager.cpp
    
    ${FARFOCEL_SOURCE_DIR}/Function/EventManager.cpp
    ${FARFOCEL_SOURCE_DIR}/Function/InputManager.cpp

    ${FARFOCEL_SOURCE_DIR}/Animation/AnimationManager.cpp    
)

set(FARFOCEL_INCLUDE_FILES_MANUAL
    ${FARFOCEL_INCLUDE_DIR}/Core/Farfocel.hpp
    ${FARFOCEL_INCLUDE_DIR}/Core/Runtime.hpp

    ${FARFOCEL_INCLUDE_DIR}/Scene/IScene.hpp
    ${FARFOCEL_INCLUDE_DIR}/Scene/SceneManager.hpp

    ${FARFOCEL_INCLUDE_DIR}/Resource/ResourceManager.hpp
    ${FARFOCEL_INCLUDE_DIR}/Resource/AssetStorer.hpp
    ${FARFOCEL_INCLUDE_DIR}/Resource/TextureAtlas.hpp
    
    ${FARFOCEL_INCLUDE_DIR}/Function/EventManager.hpp
    ${FARFOCEL_INCLUDE_DIR}/Function/InputManager.hpp
    ${FARFOCEL_INCLUDE_DIR}/Function/FunctionBinder.hpp

    ${FARFOCEL_INCLUDE_DIR}/Animation/AnimationManager.hpp
    ${FARFOCEL_INCLUDE_DIR}/Animation/Animation.hpp
)

add_library(${PROJECT_NAME} STATIC ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC ${FARFOCEL_INCLUDE_DIR}/)

set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Sandbox-Binary/)
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Sandbox-Binary/)

set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Sandbox-Binary/Debug)
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Sandbox-Binary/Release)

set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/Sandbox-Binary/Debug)
set_target_properties(${PROJECT_NAME} PROPERTIES CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/Sandbox-Binary/Release)

install(TARGETS ${PROJECT_NAME})
