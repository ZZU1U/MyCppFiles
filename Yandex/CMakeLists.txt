cmake_minimum_required(VERSION 3.13)  # CMake version check
project(main)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)

add_definitions(-DDEBUG)

# Add main.cpp file of the project root directory as a source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main ${SOURCE_FILES})