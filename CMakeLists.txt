cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17) # C++17...
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-std=c++17")
project(Terraforming-Carta CXX)

set(Carta_src
    src/main.cpp
)

## Define the executable
add_executable(TERRAFORMING_Carta ${Carta_src})
target_include_directories(TERRAFORMING_Carta PRIVATE C:/Users/thebe/Desktop/Terraforming-carta/src)
