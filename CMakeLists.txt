cmake_minimum_required(VERSION 3.27)
project(ROI_Video_Encoder)

set(CMAKE_CXX_STANDARD 14)

add_executable(ROI_Video_Encoder
        src/main.cpp
        include/Encoder.h
        src/Encoder.cpp
        src/ROIManager.cpp
        include/ROIManager.h)
