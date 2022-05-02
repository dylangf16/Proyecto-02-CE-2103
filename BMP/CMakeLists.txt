cmake_minimum_required(VERSION 3.22)
project(BMP)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(BMP
        BmpTutorial.cpp
        Image.cpp
        Image.h)
