add_executable(Main
    main.c
)

add_library(Stack
    stack.c
)

target_include_directories(Main
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(Main
    PRIVATE
        Stack
)

target_include_directories(Stack
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)