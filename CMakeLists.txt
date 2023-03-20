cmake_minimum_required(VERSION 3.24)
project(FightClub)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FightClub
        Ability.cpp
        Ability.h
        Character.cpp
        Character.h
        Decision.cpp
        Decision.h
        Game.cpp
        Game.h
        main.cpp Team.cpp)
