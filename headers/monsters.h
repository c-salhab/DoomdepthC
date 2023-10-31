/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef MONSTERS_H
#define MONSTERS_H

typedef struct {
    int life;
    int min_power;
    int max_power;
    int defense;
} Monster;


void init_monster(int life, int min_power, int max_power, int defense);
void scale_monster_stats(Monster **list_monsters, int num_monsters, int character_level);
Monster ** generate_monster();

#endif