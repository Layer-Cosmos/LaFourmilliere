cmake_minimum_required(VERSION 3.8)
project(LaFourmilliere)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp test.cpp test.h)
add_executable(LaFourmilliere ${SOURCE_FILES})