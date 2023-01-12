cmake_minimum_required(VERSION 3.22)

project(
  PROJECT_NAME
  VERSION 1.0.0
  LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(run_practice_08_1 practice_1.cpp)
add_executable(run_practice_08_2 practice_2.cpp)

# Easy Problems
add_executable(run_problem_08_01 problem_01.cpp)
add_executable(run_problem_08_02 problem_02.cpp)
add_executable(run_problem_08_03 problem_03.cpp)
add_executable(run_problem_08_04 problem_04.cpp)
add_executable(run_problem_08_05 problem_05.cpp)

# Medium Problems
add_executable(run_problem_08_06 problem_06.cpp)
add_executable(run_problem_08_07 problem_07.cpp)
add_executable(run_problem_08_08 problem_08.cpp)
add_executable(run_problem_08_09 problem_09.cpp)
add_executable(run_problem_08_10 problem_10.cpp)
add_executable(run_problem_08_11 problem_11.cpp)

# Hard problems
add_executable(run_problem_08_12 problem_12.cpp)
add_executable(run_problem_08_13 problem_13.cpp)
add_executable(run_problem_08_14 problem_14.cpp)
add_executable(run_problem_08_15 problem_15.cpp)
add_executable(run_problem_08_16 problem_16.cpp)
