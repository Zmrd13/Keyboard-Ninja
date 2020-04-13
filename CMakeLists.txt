cmake_minimum_required(VERSION 3.13)
project(Keyboard_Ninja)

set(CMAKE_CXX_STANDARD 14)
file(MAKE_DIRECTORY build/bin)
file(COPY src/ DESTINATION build/bin)
add_executable(Keyboard_Ninja.exe main.cpp)


