cmake_minimum_required(VERSION 3.10)
project(TrafficModel)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(traffic_model
        Sources/main.cpp
        Sources/Traffic_Model.cpp
        Sources/Uniform_Model.cpp
        Sources/Poisson_Model.cpp
        Sources/File_Manager.cpp
)
