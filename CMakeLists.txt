cmake_minimum_required(VERSION 3.30)
project(sdl3-wrapper)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH /Users/rodri/local/cmake)
set(CMAKE_LIBRARY_PATH /Users/rodri/local/lib/x64)


include_directories(/Users/rodri/local/include)
link_directories(/Users/rodri/local/lib/x64)
find_package(SDL3 REQUIRED)
if(SDL3_FOUND)
    message("ENCONTRADO")
else()
    message(FATAL_ERROR "no encontrado")
endif()
find_package(SDL3_image REQUIRED)
if(SDL3_image_FOUND)
    message("ENCONTRADO")
else()
    message(FATAL_ERROR "no encontrado")
endif()

add_executable(sdl3-wrapper main.cpp
        game.cpp
        game.h
        texturemanager.cpp
        texturemanager.h)
target_link_libraries(sdl3-wrapper SDL3 SDL3_image)
