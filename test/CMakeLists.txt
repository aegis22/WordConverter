cmake_minimum_required(VERSION 3.14)

project(WordConverter_test VERSION 1.0)

set(Sources
    WordConverter_test.cpp
)

add_executable(${PROJECT_NAME} ${Sources})

target_link_libraries(${PROJECT_NAME} PUBLIC
    gtest_main
)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
