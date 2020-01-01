cmake_minimum_required(VERSION 3.15)
project(Data_structures_and_algorithms_in_C C)

set(CMAKE_C_STANDARD 99)
file(GLOB SOURCES
        *.h						//*号对应具体的文件名
        *.cpp
        )

add_executable(Data_structures_and_algorithms_in_C main.c)
