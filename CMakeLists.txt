cmake_minimum_required(VERSION 3.12)
project(A.C.I.D.)

set(CMAKE_CXX_STANDARD 14)


include_directories (
        include
        include/test
)

set (
        HDRS

        include/i_system.h
        include/active_system.h
        include/reactive_system.h
        include/sub_system.h
)

set (
        SRCS

        src/main.cpp
)

add_executable(ACID  ${SRCS} ${HDRS})