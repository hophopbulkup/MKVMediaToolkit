cmake_minimum_required(VERSION 4.3)
project(MKVMediaToolkit)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MKVMediaToolkit
        main.cpp
        core/process_runner.h
        core/process_runner.cpp
        operations/remux.h
        operations/remux.cpp)
