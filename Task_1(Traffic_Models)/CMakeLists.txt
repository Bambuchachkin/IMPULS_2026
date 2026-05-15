cmake_minimum_required(VERSION 3.10)
project(TrafficModel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(traffic_model
        cpp/main.cpp
        cpp/Traffic_Model.cpp
        cpp/Uniform_Model.cpp
        cpp/Poisson_Model.cpp
        cpp/File_Manager.cpp
)
