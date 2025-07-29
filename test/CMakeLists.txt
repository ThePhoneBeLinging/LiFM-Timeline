cmake_minimum_required(VERSION 3.25)
project(LiFM_TimelineTests)

set(CMAKE_CXX_STANDARD 20)

add_executable(LiFM_TimelineTests
    TestTemplate.cpp
)

target_link_libraries(LiFM_TimelineTests PUBLIC
        GTest::gtest
        GTest::gtest_main
        LiFM_Timeline
)