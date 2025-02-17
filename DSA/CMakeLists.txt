cmake_minimum_required(VERSION 3.30)
project(D_S_A)

set(CMAKE_CXX_STANDARD 20)

add_executable(D_S_A main.cpp
        bubble_sort.h
        quick_sort.h
        merge_sort.h
        insertion_sort.h
        selection_sort.h
        radix_sort.h)
