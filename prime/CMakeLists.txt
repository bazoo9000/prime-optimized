cmake_minimum_required(VERSION 3.10)

project(PrimeOptimized)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PrimeOptimized
    src/main.cpp
    src/test.cpp
    src/prime.cpp
)

target_include_directories(PrimeOptimized PRIVATE include)