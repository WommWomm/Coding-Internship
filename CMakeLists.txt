cmake_minimum_required(VERSION 3.20)
project(Steinerbaum_Projekt)

set(CMAKE_CXX_STANDARD 20)

add_executable(Steinerbaum_Projekt main.cpp pin.cpp Pin.h get_data_stp.h get_data_stp.cpp distance_matrix.cpp distance_matrix.h Edge.cpp Edge.h)

