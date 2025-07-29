cmake_minimum_required(VERSION 3.31)
project(LiFM_Timeline)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
        Utility
        GIT_REPOSITORY https://github.com/ThePhoneBeLinging/Utility
        GIT_TAG v1.0.0
)
FetchContent_MakeAvailable(Utility)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1  # Specify the version you need
)
FetchContent_MakeAvailable(googletest)

add_subdirectory(src)
add_subdirectory(test)

target_include_directories(LiFM_Timeline PUBLIC include)
target_include_directories(LiFM_Timeline PRIVATE src)