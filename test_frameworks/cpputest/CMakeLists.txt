cmake_minimum_required(VERSION 3.22)

project("CppUTest Tutorial")

include(FetchContent)
include(CTest)

FetchContent_Declare(CppUTest
    GIT_REPOSITORY https://github.com/cpputest/cpputest.git
    GIT_TAG master
)

FetchContent_MakeAvailable(CppUTest)

add_subdirectory(src)
add_subdirectory(test)
