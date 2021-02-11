cmake_minimum_required(VERSION 3.14)
project(AETG2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AETG2
        main.cpp
        PairMap.cpp
        PairMap.h)
