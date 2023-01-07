cmake_minimum_required(VERSION 3.22)

project(
  Printing
  VERSION 1.0.0
  LANGUAGES C CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Options
option(USE_CONAN "Whether to use conan" OFF)
option(USE_VCPKG "Whether to use vcpkg" OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable a Code Coverage build." ON)

option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable to add iwyu." OFF)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)
option(ENABLE_CPPCHECK "Enable to add cppcheck." ON)

option(ENABLE_SANITIZE_ADDR "Enable to sanitize address (Unix only)." ON)
option(ENABLE_SANITIZE_UNDEF "Enable to sanitize undefined (Unix only)." ON)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

# Project/Library Names
set(LIBRARY_NAME "lib")
set(UNIT_TEST_NAME "unit_tests")
set(EXECUTABLE_NAME "main")

# CMake modules
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(FetchContent)
include(AddGitSubmodule)
include(Docs)
include(Warnings)
include(Tools)
include(LTO)
include(ConfigSafeGuards)

add_cmake_format_target()
add_clang_format_target()

if (ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif ()

if (ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif ()

if (ENABLE_LTO)
    find_lto(CXX)
endif ()

# External libraries
if (USE_CONAN)
    message("==> Using Conan")
    include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
    find_package(nlohmann_json)
    find_package(fmt)
    find_package(spdlog)
    find_package(Catch2)
    find_package(cxxopts)
elseif (USE_VCPKG)
    message("==> Using VCPKG")
    include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)
    find_package(nlohmann_json)
    find_package(fmt)
    find_package(spdlog)
    find_package(Catch2)
    find_package(cxxopts)
else () # Use FetchContent
    message("==> Using FetchContent")
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.9
        GIT_SHALLOW TRUE)
    FetchContent_MakeAvailable(Catch2)
endif ()

add_executable(run_homework_01 homework_01.cpp)
add_executable(run_homework_02 homework_02.cpp)
add_executable(run_homework_03 homework_03.cpp)

