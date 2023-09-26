cmake_minimum_required(VERSION 3.26)
project(Data_Structures_Implementation)

set(CMAKE_CXX_STANDARD 20)

add_executable(Data_Structures_Implementation
        Headers/StaticArray.h
        Headers/LinkedList.h
        Headers/DynamicArray.h
        Sources/StaticArray.cpp
        Sources/DynamicArray.cpp
        Sources/LinkedList.cpp
        main.cpp
)
