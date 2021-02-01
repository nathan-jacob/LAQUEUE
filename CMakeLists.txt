cmake_minimum_required(VERSION 3.17)
project(laqueue_nathan_jacob)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(laqueue_nathan_jacob
        client.cpp
        client.h
        LaQueue.cpp
        lqueue.cpp
        lqueue.h
        PQueue.cpp
        PQueue.h
        server.cpp
        server.h
        siginfo.h)
