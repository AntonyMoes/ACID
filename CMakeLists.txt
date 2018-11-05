cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 14)


include_directories (
        include
        include/test
)

add_executable(ACID  src/main.cpp)