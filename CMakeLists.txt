cmake_minimum_required(VERSION 3.27)
project(Starter CXX)

set(CMAKE_CXX_STANDARD 20)

build_application(
    SOURCES
    application.cpp
)

generate_compile_commands()
