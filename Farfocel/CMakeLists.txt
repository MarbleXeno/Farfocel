cmake_minimum_required (VERSION 3.5)

project(Farfocel)

# Static SFML libs are currently only possible on Windows, as we compile them ourselfs. On Linux this project uses only dynamic SFML libs
if(WIN32)
    # Fetch the SFML v2.5.1 GitHub project.
    include(FetchContent)
    FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
    FetchContent_MakeAvailable(SFML)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(FARFOCEL_SOURCE_DIR src/)
set(FARFOCEL_INCLUDE_DIR include/)

set(CMAKE_DEBUG_POSTFIX "-d")

if(MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
endif()

file(GLOB_RECURSE FARFOCEL_SOURCE_FILES CONFIGURE_DEPENDS ${FARFOCEL_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FARFOCEL_INCLUDE_FILES CONFIGURE_DEPENDS ${FARFOCEL_INCLUDE_DIR}/*.hpp)

add_library(${PROJECT_NAME} STATIC ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES}/)

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-audio)

#target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC ${FARFOCEL_INCLUDE_DIR}/)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)

install(TARGETS ${PROJECT_NAME})
