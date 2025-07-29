cmake_minimum_required(VERSION 3.31)
project(LiFM_Timeline)

set(CMAKE_CXX_STANDARD 20)

add_library(LiFM_Timeline
        LiFMTimeline.cpp
)

target_link_libraries(LiFM_Timeline PUBLIC Utility)
