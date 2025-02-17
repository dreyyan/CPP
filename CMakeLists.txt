cmake_minimum_required(VERSION 3.29)
project(_cpp)
set(CMAKE_CXX_STANDARD 20)
# Add the executable
add_executable(1 STL_containers/array_left_rotate.cpp)
add_executable(2 STL_containers/array_right_rotate.cpp)

add_executable(3 STL_containers/array_remove_duplicates.cpp)
