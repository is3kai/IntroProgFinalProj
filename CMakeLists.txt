cmake_minimum_required(VERSION 3.26)
project(IntroProgFinalProj)

set(CMAKE_CXX_STANDARD 20)

add_executable(IntroProgFinalProj main.cpp
        playerfunctions.h
        playerfunctions.cpp
        enemyfunctions.h
        enemyfunctions.cpp
        gamefunctions.h
        gamefunctions.cpp)
