cmake_minimum_required(VERSION 3.22)

project(
  Variables
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(run_homework_03_01 homework_01.cpp)
add_executable(run_homework_03_02 homework_02.cpp)
add_executable(run_homework_03_03 homework_03.cpp)
