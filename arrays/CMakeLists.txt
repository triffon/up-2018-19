cmake_minimum_required(VERSION 3.7)
project(arrays)
file(GLOB SOURCES "*.cpp")
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 11)
add_executable(arrays ${SOURCES})