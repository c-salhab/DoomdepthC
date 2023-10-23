/*
Created by: Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date: 27/09/2023
Projet DoomdepthC
*/

#ifndef SPELLS_H
#define SPELLS_H

#include "character.h"

typedef struct {
    char *spell_name;
    int cost;
    int offensive;
    int defensive;
    int heal;
} Spell;

//void choose_another_spell(Character *character);
//char *get_offensive(Character *character);
//void select_offensive_spell(Character *character);

#endif
