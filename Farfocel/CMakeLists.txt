cmake_minimum_required(VERSION 3.5)

project(Farfocel)

message(STATUS "------------------------")
message(STATUS "Fetching dependencies...")

include(FetchContent)

if(WIN32)
    message(STATUS "Fetching SFML...")

    # Fetch SFML
    FetchContent_Declare(
            SFML
            GIT_REPOSITORY  https://github.com/SFML/SFML.git
            GIT_TAG         2.6.0
            GIT_PROGRESS    TRUE
    )

    FetchContent_MakeAvailable(SFML)
else()
    message(STATUS "Looking for SFML...")
    find_package(SFML 2.5 COMPONENTS graphics window system audio)
endif()

message(STATUS "Fetching Dear ImGui...")
# Fetch ImGui
FetchContent_Declare(
    imgui
    GIT_REPOSITORY  https://github.com/ocornut/imgui.git
    GIT_TAG         v1.89.5
    GIT_PROGRESS    TRUE
)
FetchContent_Populate(imgui)

message(STATUS "Fetching ImGui-SFML...")
# Fetch ImGui-SFML
FetchContent_Declare(
    ImGui-SFML
    GIT_REPOSITORY  https://github.com/eliasdaler/imgui-sfml.git
    GIT_TAG         master
    GIT_PROGRESS    TRUE
)

set(IMGUI_DIR ${imgui_SOURCE_DIR})
set(IMGUI_SFML_FIND_SFML OFF)

FetchContent_MakeAvailable(ImGui-SFML)

if(MSVC)
    if(${BUILD_SHARED_LIBS})

    else()
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
    endif()
endif()

# Variables
set(BUILD_SHARED_LIBS OFF CACHE BOOL "Specify if you want to build dependencies statically or dynamically")
set(FARFOCEL_BUILD_SHARED OFF CACHE BOOL "Specify if you want to build Farfocel as a shared or static library")

set(FARFOCEL_SOURCE_DIR src/)
set(FARFOCEL_INCLUDE_DIR include/)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# search for Farfocel source files
file(GLOB_RECURSE FARFOCEL_SOURCE_FILES CONFIGURE_DEPENDS ${FARFOCEL_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE FARFOCEL_INCLUDE_FILES CONFIGURE_DEPENDS ${FARFOCEL_INCLUDE_DIR}/*.hpp)
# -search for Farfocel source files

if(${FARFOCEL_BUILD_SHARED})
    add_library(${PROJECT_NAME} SHARED ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES})
else()
    add_library(${PROJECT_NAME} STATIC ${FARFOCEL_SOURCE_FILES} ${FARFOCEL_INCLUDE_FILES})
endif()

target_link_libraries(${PROJECT_NAME} PUBLIC sfml-graphics sfml-window sfml-system sfml-audio ImGui-SFML)

target_include_directories(${PROJECT_NAME} PUBLIC ${FARFOCEL_INCLUDE_DIR})

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/Farfocel-Library/)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

install(TARGETS ${PROJECT_NAME})
