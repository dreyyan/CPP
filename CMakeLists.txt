cmake_minimum_required(VERSION 3.29)
project(_cpp)

set(CMAKE_CXX_STANDARD 20)

# Gather all .cpp files from both STL_containers and the current directory
file(GLOB SOURCES "STL_containers/*.cpp" ".prog/*.cpp" "sorting_algorithms/*.cpp" "C_style/*.cpp" ".exercises/*.cpp" "*.cpp")

# Use a set to track unique target names
set(TARGET_NAMES)

foreach(SOURCE ${SOURCES})
    # Get relative path (exclude full directory path)
    file(RELATIVE_PATH REL_PATH "${CMAKE_SOURCE_DIR}" "${SOURCE}")

    # Replace slashes with underscores to create a unique name
    string(REPLACE "/" "_" EXEC_NAME "${REL_PATH}")
    string(REPLACE "\\" "_" EXEC_NAME "${EXEC_NAME}")

    # Remove .cpp extension to avoid redundancy
    string(REPLACE ".cpp" "" EXEC_NAME "${EXEC_NAME}")

    # Ensure unique target name
    if (EXEC_NAME IN_LIST TARGET_NAMES)
        math(EXPR COUNTER "${COUNTER} + 1")
        set(EXEC_NAME "${EXEC_NAME}_${COUNTER}")
    endif()

    # Store this name to avoid duplicates
    list(APPEND TARGET_NAMES ${EXEC_NAME})

    # Create an executable
    add_executable(${EXEC_NAME} ${SOURCE}
            sorting_algorithms/print_array.h)
endforeach()
