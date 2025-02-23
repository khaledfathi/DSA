cmake_minimum_required(VERSION 3.10) 
project(DSA)  
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(run_dsa #exe file name
    main.cpp
    src/exceptions/dsa_exceptions.cpp
)