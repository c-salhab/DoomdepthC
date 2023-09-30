/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/monsters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


Monster * init_monster(int life, int min_power, int max_power, int defense) {

    Monster * monster = malloc(sizeof(Monster));

    monster->life = life;
    monster->min_power = min_power;
    monster->max_power = max_power;
    monster->defense = defense;

}

Monster ** generate_monster() {
    srand(time(NULL));
    int n = (rand() % 30) + 1;

    Monster **list_monster = malloc(sizeof(Monster*) * (n + 1));

    for(int i = 0; i < n; i++) {
        list_monster[i] = malloc(sizeof(Monster));

        int life = (rand() % 100) + 1;
        int min_power = (rand() % 50) + 1;
        int max_power = (rand() % 100) + 1;
        int defense = (rand() % 100) + 1;

        list_monster[i]->life = life;
        list_monster[i]->min_power = min_power;
        list_monster[i]->max_power = max_power;
        list_monster[i]->defense = defense;
    }

    list_monster[n] = NULL;

    return list_monster;
}

