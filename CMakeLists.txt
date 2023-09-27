cmake_minimum_required(VERSION 3.26)
project(DoomdepthC C)

set(CMAKE_C_STANDARD 11)

add_executable(DoomdepthC
        battle_phase.c
        equipment.c
        Game.c
        main.c
        monster.c
        players.c
        spell.c)
