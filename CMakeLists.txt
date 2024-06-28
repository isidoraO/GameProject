cmake_minimum_required(VERSION 3.28)
project(Proyecto C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(TDAs)

add_executable(Proyecto
        TDAs/List.c
        TDAs/List.h
        Rooms.c
        Rooms.h
        Game.c)