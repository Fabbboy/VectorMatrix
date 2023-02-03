cmake_minimum_required(VERSION 3.24)
project(VectorMatrix C)

set(CMAKE_C_STANDARD 11)

add_library(VectorMatrix Vector.c Matrix.h Matrix.c)
