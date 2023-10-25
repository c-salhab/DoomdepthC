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

Spell *create_spell(char *spell_name, int cost, int offensive, int defensive, int heal);
//char *get_offensive(Character *character);
//void set_offensive(Character *character, Spell *selection);
//void select_offensive_spell(Character *character);
//char *get_defensive(Character *character);
//void set_defensive(Character *character, Spell *selection);
//void select_defensive_spell(Character *character);
//char *get_heal(Character *character);
//void set_heal(Character *character, Spell *selection);
//void select_heal_spell(Character *character);
//void choose_another_spell(Character *character);

#endif
