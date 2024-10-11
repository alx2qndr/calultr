cmake_minimum_required(VERSION 3.14)
project(calultr VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable(${PROJECT_NAME} "src/main.cpp" "include/calultr/program.cpp" "include/calultr/program.hpp")
include_directories(${PROJECT_NAME} PRIVATE "include")