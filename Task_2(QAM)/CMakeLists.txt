cmake_minimum_required(VERSION 3.31)
project(QAM)

set(CMAKE_CXX_STANDARD 20)

add_executable(QAM cpp/main.cpp
        cpp/QAM_Modulator.cpp
        cpp/QAM_Demodulator.cpp
        cpp/Generator.cpp
        cpp/Noise.cpp
)
