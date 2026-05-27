cmake_minimum_required(VERSION 3.27)
project(Starter CXX)

set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy; -warnings-as-errors=.")
# 1. Find the clang-tidy executable
find_program(CLANG_TIDY_EXE NAMES clang-tidy)

# 1. Find the clang-tidy executable
# find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    # 2. Set the global variable to enable clang-tidy
    #    The variable is set to a list: [executable, arg1, arg2, ...]
    #    In this case, no arguments are needed because:
    #    - Clang-Tidy automatically searches for and uses the '.clang-tidy' file.
    #    - The 'WarningsAsErrors: "*"' inside your .clang-tidy file handles
    #      making the checks fail the build.
    set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} CACHE STRING "Clang-Tidy tool to run on C++ sources" FORCE)
    
    message(STATUS "Clang-Tidy enabled. Build will fail on check violations due to 'WarningsAsErrors: *' in .clang-tidy.")
else()
    message(WARNING "clang-tidy executable not found. Static analysis is disabled.")
endif()

build_application(
    SOURCES
    application.cpp
)

generate_compile_commands()
