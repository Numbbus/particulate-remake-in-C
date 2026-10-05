cmake_minimum_required(VERSION 3.24)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

project(particulate VERSION 1.0)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Raylib 
##############################################################

set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        DOWNLOAD_EXTRACT_TIMESTAMP OFF
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_MakeAvailable(raylib)
    endif()    
endif()
##############################################################

file(GLOB_RECURSE SRC_FILES src/*.c)

if(WIN32)
add_executable(particulate WIN32 ${SRC_FILES})
else()
add_executable(particulate ${SRC_FILES})
endif()

target_link_libraries(particulate raylib)