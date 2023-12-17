cmake_minimum_required(VERSION 3.22)

project("GoogleTest Tutorial")

include(FetchContent)
include(CTest)

FetchContent_Declare(GoogleTest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main
)

FetchContent_MakeAvailable(GoogleTest)

add_subdirectory(src)
add_subdirectory(test)