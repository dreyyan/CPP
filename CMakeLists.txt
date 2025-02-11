cmake_minimum_required(VERSION 3.29)
project(CLion)

set(CMAKE_CXX_STANDARD 20)

# Find all .cpp files in the project directory
file(GLOB CPP_FILES "*.cpp")

# Create an executable for each .cpp file
foreach(SOURCE_FILE ${CPP_FILES})
    get_filename_component(EXEC_NAME ${SOURCE_FILE} NAME_WE)
endforeach()
