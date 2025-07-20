cmake_minimum_required(VERSION 3.31)
project(firstsdl3)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_PREFIX_PATH "/home/rodrigo/local/lib/cmake/SDL3;/home/rodrigo/local/lib/cmake/SDL3_image")

find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)

include_directories(/home/rodrigo/local/include)


add_executable(firstsdl3 main.cpp
        game.cpp
        game.h
        texturemanager.cpp
        texturemanager.h)

target_link_libraries(firstsdl3 ${SDL3_LIBRARIES} SDL3_image::SDL3_image)
