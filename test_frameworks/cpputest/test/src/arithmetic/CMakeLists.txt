add_library(TestArithmetic
    test_arithmetic.cpp
)

target_include_directories(TestArithmetic
    PRIVATE
        ${CMAKE_SOURCE_DIR}/test/include
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(TestArithmetic
    PRIVATE
        CppUTest
        Arithmetic
)