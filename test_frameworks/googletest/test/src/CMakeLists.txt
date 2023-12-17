add_executable(TestMain
    test_main.cpp
    test_stack.cpp
)

target_include_directories(TestMain
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(TestMain
    PRIVATE
        gtest
        Stack
)

enable_testing()
add_test(TestMain TestMain)