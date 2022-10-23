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

# i dont know if this is the best way to do it... it works tho
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Binary/Debug)

    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Binary/Debug)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Binary/Release)

    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Binary/Release)
endif()

set(CMAKE_DEBUG_POSTFIX "-d")

# yeah im lazy and i dont want to include every single source file by hand
file(GLOB_RECURSE FARFOCEL_SOURCE_FILES ${FARFOCEL_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FARFOCEL_INCLUDE_FILES ${FARFOCEL_INCLUDE_DIR}/*.hpp)

add_library(${PROJECT_NAME} STATIC ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC ${FARFOCEL_INCLUDE_DIR}/)

install(TARGETS ${PROJECT_NAME})
