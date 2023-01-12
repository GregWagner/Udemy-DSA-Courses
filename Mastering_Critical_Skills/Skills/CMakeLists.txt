cmake_minimum_required(VERSION 3.22)

project(
  MasteringCriticalSkills
  VERSION 1.0.0
  LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


add_subdirectory(Section_03_Printing)
add_subdirectory(Section_04_Data_Types_and_Variables)
add_subdirectory(Section_05_Operators)
add_subdirectory(Section_06_Selection)
add_subdirectory(Section_07_Loops)
add_subdirectory(Section_08_1D_Arrays)
add_subdirectory(Section_09_Char_Arrays)
add_subdirectory(Section_10_Multidimensional_Arrays)
