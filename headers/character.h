/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "spells.h"
#include "inventory.h"
#include "monsters.h"

typedef struct {

    char *username;
    int is_alive;
    float current_health;
    float current_mana;

    int level;
    int exp;

    int gold;
    Spell *offensive_spell;
    Spell *defensive_spell;
    Spell *heal_spell;
    Inventory *inventory;

} Character;

int exp_needed_to_level_up = 50;
int max_health = 1000;
int max_mana = 1000;

int is_printed = 0;

Character * init_character(char *name);

void show_specs(Character *character);

void fight(Character *character, Monster **list_monster, int num_monsters);

#endif