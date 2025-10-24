cmake_minimum_required(VERSION 3.10)
project(TDD_Assignment)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add all cpp files
add_executable(tdd_assignment
    main.cpp
    tshirts.cpp
    tshirts_test.cpp
    misaligned.cpp
    misaligned_test.cpp
    weatherreport.cpp
    weatherreport_test.cpp
)
