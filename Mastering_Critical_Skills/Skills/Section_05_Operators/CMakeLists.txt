cmake_minimum_required(VERSION 3.22)

project(
  Variables
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Easy Problems
add_executable(run_homework_01 homework_01.cpp)
add_executable(run_homework_02 homework_02.cpp)
add_executable(run_homework_03 homework_03.cpp)
add_executable(run_homework_04 homework_04.cpp)
add_executable(run_homework_05 homework_05.cpp)
add_executable(run_homework_06 homework_06.cpp)
add_executable(run_homework_07 homework_07.cpp)
add_executable(run_homework_08 homework_08.cpp)
add_executable(run_homework_09 homework_09.cpp)

# Medium Problems
add_executable(run_homework_10 homework_10.cpp)
add_executable(run_homework_11 homework_11.cpp)
add_executable(run_homework_12 homework_12.cpp)

# Hard Problems
add_executable(run_homework_13 homework_13.cpp)
add_executable(run_homework_14 homework_14.cpp)
