cmake_minimum_required(VERSION 3.29)
project(CLion)

set(CMAKE_CXX_STANDARD 20)

add_executable(C__ deque_max_sliding_window.cpp
        STL_containers/stack_reverse_string.cpp
        STL_containers/stack_balanced_parentheses.cpp
        STL_containers/stack_class.cpp
        STL_containers/stack_next_greater_element.cpp
        STL_containers/stack_recursion_sort.cpp
        STL_containers/array_find_largest_smallest_element.cpp
        STL_containers/array_reverse.cpp
        STL_containers/array_sum_of_elements.cpp
        STL_containers/array_count_even_odd.cpp
        STL_containers/array_second_largest_element.cpp
        STL_containers/array_is_sorted.cpp
        STL_containers/array_merge_two_sorted_arrays.cpp)