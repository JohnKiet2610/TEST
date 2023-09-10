cmake_minimum_required(VERSION 3.25)
project(Assignment2_2)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES "*.cpp")
add_executable(Assignment2_2 ${SOURCES} player.cpp)
