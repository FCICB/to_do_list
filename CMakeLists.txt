cmake_minimum_required(VERSION 3.20)
project(Updated_to_do_list)

set(CMAKE_CXX_STANDARD 23)

add_executable(Updated_to_do_list main.cpp task.cpp task.h fileHandling.cpp fileHandling.h list.cpp list.h screen.cpp screen.h)
