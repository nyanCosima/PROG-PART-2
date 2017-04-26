cmake_minimum_required(VERSION 3.6)
project(PROG_PART_2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Bus.cpp
        Bus.h
        Company.cpp
        Company.h
        Driver.cpp
        Driver.h
        Line.cpp
        Line.h
        main.cpp
        Shift.cpp
        Shift.h)

add_executable(PROG_PART_2 ${SOURCE_FILES})