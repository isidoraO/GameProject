cmake_minimum_required(VERSION 3.28)
project(Proyecto C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(TDAs)

add_executable(Proyecto
        TDAs/List.c
        TDAs/List.h
        TDAs/Stack.h
        TDAs/Map.c
        TDAs/Map.h
        Rooms.c
        Rooms.h
        Game.c)