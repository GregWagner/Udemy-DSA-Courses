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

# Options
option(USE_CONAN "Whether to use conan" OFF)
option(USE_VCPKG "Whether to use vcpkg" OFF)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." ON)

option(ENABLE_TESTING "Enable a Unit Testing build." ON)
option(ENABLE_COVERAGE "Enable a Code Coverage build." ON)

option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable to add iwyu." OFF)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)
option(ENABLE_CPPCHECK "Enable to add cppcheck." ON)

option(ENABLE_SANITIZE_ADDR "Enable to sanitize address (Unix only)." OFF)
option(ENABLE_SANITIZE_UNDEF "Enable to sanitize undefined (Unix only)." OFF)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." OFF)

option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

# Project/Library Names
set(LIBRARY_NAME "lib")
set(UNIT_TEST_NAME "unit_tests")
set(EXECUTABLE_NAME "main.cpp")

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

# Setup compile options
message("==> Warnings Active for: ${TARGET_SET_WARNINGS_TARGET}")
message("==> Warnings as Errors: ${TARGET_SET_WARNINGS_AS_ERRORS}")

set(MSVC_WARNINGS
        # Baseline
        /W4 # Baseline reasonable warnings
        /permissive- # standards conformance mode for MSVC compiler
        # C and C++ Warnings
        /w14242 # conversion from 'type1' to 'type1', possible loss of data
        /w14287 # unsigned/negative constant mismatch
        /w14296 # expression is always 'boolean_value'
        /w14311 # pointer truncation from 'type1' to 'type2'
        /w14826 # Conversion from 'type1' to 'type_2' is sign-extended
        /w44062 # enumerator in a switch of enum 'enumeration' is not handled
        /w44242 # conversion from 'type1' to 'type2', possible loss of data
        # C++ Only
        /w14928 # more than one implicitly user-defined conversion
        /w14263 # function does not override any base class virtual function
        /w14265 # class has virtual functions, but destructor is not virtual
        )

set(CLANG_WARNINGS
        # Baseline
        -Wall
        -Wextra # reasonable and standard
        -Wpedantic # warn if non-standard is used
        # C and C++ Warnings
        -Wshadow # if a variable declaration shadows one from a parent context
        -Wunused # warn on anything being unused
        -Wformat=2 # warn on security issues around functions that format output
        -Wcast-align # warn for potential performance problem casts
        -Wconversion # warn on type conversions that may lose data
        -Wnull-dereference # warn if a null dereference is detected
        # C++ Warnings
        -Wnon-virtual-dtor # if a class with virtual func has a non-virtual dest
        -Wold-style-cast # warn for c-style casts
        -Woverloaded-virtual # if you overload (not override) a virtual function
        -Weffc++ # violations from Scott Meyers’ Effective C++
        )

set(GCC_WARNINGS ${CLANG_WARNINGS})

if (${TARGET_SET_WARNINGS_AS_ERRORS})
    set(CLANG_WARNINGS ${CLANG_WARNINGS} -Werror)
    set(GCC_WARNINGS ${GCC_WARNINGS} -Werror)
    set(MSVC_WARNINGS ${MSVC_WARNINGS} /WX)
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(WARNINGS ${MSVC_WARNINGS})
elseif (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(WARNINGS ${CLANG_WARNINGS})
elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(WARNINGS ${GCC_WARNINGS})
endif ()
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${WARNINGS}")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Sub directories
add_subdirectory(Section_03_Printing)
add_subdirectory(Section_04_Data_Types_and_Variables)
add_subdirectory(Section_05_Operators)
add_subdirectory(Section_06_Selection)
add_subdirectory(Section_07_Loops)
add_subdirectory(Section_08_1D_Arrays)
add_subdirectory(Section_09_Char_Arrays)
add_subdirectory(Section_10_Multidimensional_Arrays)
