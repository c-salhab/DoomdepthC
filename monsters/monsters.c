/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/monsters.h"
#include <stdlib.h>
#include <time.h>

void init_monster(int life, int min_power, int max_power, int defense) {
    // allocate memory for a new Monster
    Monster * monster = malloc(sizeof(Monster));

    // assign the provided values to the Monster's attributes
    monster->life = life;
    monster->min_power = min_power;
    monster->max_power = max_power;
    monster->defense = defense;

}

Monster ** generate_monster() {
    srand(time(NULL));
    int n = (rand() % 10) + 1;

    // allocate memory for an array of Monster pointers
    Monster **list_monster = malloc(sizeof(Monster*) * (n + 1));

    for(int i = 0; i < n; i++) {
        // allocate memory for each Monster and assign random values to its attributes
        list_monster[i] = malloc(sizeof(Monster));

        int life = (rand() % 1000) + 1;
        int min_power = (rand() % 50) + 1;
        int max_power = (rand() % 100) + 1;
        int defense = (rand() % 100) + 1;

        list_monster[i]->life = life;
        list_monster[i]->min_power = min_power;
        list_monster[i]->max_power = max_power;
        list_monster[i]->defense = defense;
    }

    // set the last element of the array to NULL to indicate the end of the list
    list_monster[n] = NULL;

    return list_monster;
}

void scale_monster_stats(Monster **list_monsters, int num_monsters, int character_level) {
    // calculate the multiplier based on the character's level
    float multiplier = 1.0 + character_level * 0.4;

    // scale the attributes of each monster in the list based on the multiplier
    for (int i = 0; i < num_monsters; i++) {
        list_monsters[i]->life = (int)(list_monsters[i]->life * multiplier);
        list_monsters[i]->min_power = (int)(list_monsters[i]->min_power * multiplier);
        list_monsters[i]->max_power = (int)(list_monsters[i]->max_power * multiplier);
        list_monsters[i]->defense = (int)(list_monsters[i]->defense * multiplier);
    }
}