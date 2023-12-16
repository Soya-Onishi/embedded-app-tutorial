add_subdirectory(arithmetic)

add_executable(Main
    main.cpp
)

target_include_directories(Main
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include 
)

target_link_libraries(Main
    PRIVATE
        Arithmetic
)