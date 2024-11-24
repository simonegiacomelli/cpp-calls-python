cmake_minimum_required(VERSION 3.30)
project(untitled3)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled3 main.cpp)

#find_package(pybind11 REQUIRED)
find_package(Python3 REQUIRED COMPONENTS Interpreter Development)
add_subdirectory(pybind11)
target_link_libraries(untitled3 PRIVATE pybind11::module Python3::Python)

