cmake_minimum_required(VERSION 3.29)
project(_cpp)

set(CMAKE_CXX_STANDARD 20)

# Gather all .cpp files in the STL_containers directory
file(GLOB SOURCES "STL_containers/*.cpp")

# Iterate over the gathered source files and create an executable for each
foreach(SOURCE ${SOURCES})
    # Extract the filename without the path or extension
    get_filename_component(EXEC_NAME ${SOURCE} NAME_WE)

    # Create an executable for each .cpp file
    add_executable(${EXEC_NAME} ${SOURCE})
endforeach()
