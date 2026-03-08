cmake_minimum_required(VERSION 4.0)
project(IntrodTTProf)

set(CMAKE_CXX_STANDARD 26)

add_executable(IntrodTTProf main.cpp
        parser.cpp
        parser.h
        Manga.cpp
        Manga.h)
