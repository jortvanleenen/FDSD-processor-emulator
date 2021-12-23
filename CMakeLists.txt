cmake_minimum_required(VERSION 3.21)
project(FDSD_Emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(FDSD_Emulator main.cpp processor.cpp processor.h)
