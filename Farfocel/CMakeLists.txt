cmake_minimum_required (VERSION 3.5)

project(Farfocel)

include(FetchContent)

FetchContent_Declare(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 2.5.1)
FetchContent_MakeAvailable(SFML)

FetchContent_Declare(ImGui GIT_REPOSITORY https://github.com/ocornut/imgui.git GIT_TAG v1.89.2)
FetchContent_MakeAvailable(ImGui)

FetchContent_Declare(ImGui-SFML GIT_REPOSITORY https://github.com/eliasdaler/imgui-sfml.git GIT_TAG master)
set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)
FetchContent_MakeAvailable(ImGui-SFML)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(FARFOCEL_SOURCE_DIR src/)
set(FARFOCEL_INCLUDE_DIR include/)

set(CMAKE_DEBUG_POSTFIX "-d")

file(GLOB_RECURSE FARFOCEL_SOURCE_FILES CONFIGURE_DEPENDS ${FARFOCEL_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FARFOCEL_INCLUDE_FILES CONFIGURE_DEPENDS ${FARFOCEL_INCLUDE_DIR}/*.hpp)

set(CompilerFlags
        CMAKE_CXX_FLAGS
        CMAKE_CXX_FLAGS_DEBUG
        CMAKE_CXX_FLAGS_RELEASE
        CMAKE_CXX_FLAGS_MINSIZEREL
        CMAKE_CXX_FLAGS_RELWITHDEBINFO
        CMAKE_C_FLAGS
        CMAKE_C_FLAGS_DEBUG
        CMAKE_C_FLAGS_RELEASE
        CMAKE_C_FLAGS_MINSIZEREL
        CMAKE_C_FLAGS_RELWITHDEBINFO
        )
foreach(CompilerFlag ${CompilerFlags})
    string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
    set(${CompilerFlag} "${${CompilerFlag}}" CACHE STRING "msvc compiler flags" FORCE)
    message("MSVC flags: ${CompilerFlag}:${${CompilerFlag}}")
endforeach()

add_library(${PROJECT_NAME} STATIC ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES})

target_link_libraries(${PROJECT_NAME} PUBLIC ImGui-SFML 
sfml-graphics sfml-window sfml-system sfml-audio)
target_include_directories(${PROJECT_NAME} PUBLIC ${FARFOCEL_INCLUDE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


install(TARGETS ${PROJECT_NAME})
