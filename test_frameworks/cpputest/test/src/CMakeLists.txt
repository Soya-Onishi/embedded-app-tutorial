add_executable(MainTest
    main_test.cpp
)

add_subdirectory(arithmetic)

target_include_directories(MainTest
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/test/include
)

# CppUTestのライブラリもリンクする必要があるので忘れずに
target_link_libraries(MainTest
    PRIVATE
        CppUTest
        Arithmetic
)

# ここでテスト機能を有効化し、AllTestsをテストに加える
# COMMANDにMainTestを指定することで、
# ビルドして出来上がった実行可能ファイルを実行してくれるようになる
enable_testing()
add_test(NAME MainTest COMMAND MainTest)