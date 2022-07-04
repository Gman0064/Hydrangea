cmake_minimum_required(VERSION 2.8.9)

project (Hydrangea)

set(CMAKE_CXX_STANDARD 14)

#Import all of the SDL2 dependencies first...
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

#Then bring in the local source files and headers into the project
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(Hydrangea ${SOURCES})
target_link_libraries(Hydrangea ${SDL2_LIBRARIES})