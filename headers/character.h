/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "spells.h"

typedef struct {
    char *username;
    int is_alive;
    float health;
    float mana;
    float physical_strength;
    float physical_defense;
    int level;
    int exp;
    int exp_needed_to_level_up;
    float max_health;
    float max_mana;

//    Spell *offensive_spell;
//    Spell *defensive_spell;
//    Spell *heal_spell;

} Character;


Character * init_character(char *name, float max_health, float max_mana);

void show_specs(Character *character);

void fight(Character *character, Monster **list_monster);

#endif