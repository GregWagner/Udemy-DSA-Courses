cmake_minimum_required(VERSION 3.22)

project(
  DSA
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Easy Problems
add_executable(run_homework_09_01 homework_01.cpp)
add_executable(run_homework_09_02 homework_02.cpp)
add_executable(run_homework_09_03 homework_03.cpp)
add_executable(run_homework_09_04 homework_04.cpp)
add_executable(run_homework_09_05 homework_05.cpp)
add_executable(run_homework_09_06 homework_06.cpp)

# Medium Problems
add_executable(run_homework_09_07 homework_07.cpp)
add_executable(run_homework_09_08 homework_08.cpp)
add_executable(run_homework_09_09 homework_09.cpp)
