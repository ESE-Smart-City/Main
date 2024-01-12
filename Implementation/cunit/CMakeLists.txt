cmake_minimum_required(VERSION 3.27)
project(ESE_Cunit C)

set(CMAKE_C_STANDARD 11)

add_executable(ESE_Cunit cunit_fileA.c
        fileA.c
        fileA_suite.c
        fileA_suite.c)
