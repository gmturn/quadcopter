cmake_minimum_required(VERSION 3.16)
project(quadcopter)

set(CMAKE_CXX_STANDARD 14)

add_executable(quadcopter main.cpp PIDFunctions.cpp PIDFunctions.h)
