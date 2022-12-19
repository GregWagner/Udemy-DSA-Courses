cmake_minimum_required(VERSION 3.22)

project(
  DSA
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(run_practice_01 practice_01.cpp)
add_executable(run_practice_02 practice_02.cpp)
add_executable(run_practice_03 practice_03.cpp)

# Easy Problems
add_executable(run_problem_01 problem_01.cpp)
add_executable(run_problem_02 problem_02.cpp)

# Medium Problems

# Hard problems
