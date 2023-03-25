cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

set(PROJECT_NAME Coding)
project("${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" Lab2.cpp )
