cmake_minimum_required(VERSION 3.1)
project(Keyboard_Ninja)

set(CMAKE_CXX_STANDARD 14)

file(MAKE_DIRECTORY build/bin)
file(MAKE_DIRECTORY build/log)
file(COPY src/ DESTINATION build/bin)
add_executable(Keyboard_Ninja.exe main.cpp lib/ArrProc.h lib/Game.h lib/GameMenu.h)


