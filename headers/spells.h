/*
Created by: Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date: 27/09/2023
Projet DoomdepthC
*/

#ifndef SPELLS_H
#define SPELLS_H

#include "character.h"

typedef struct {
    int id;
    char *spell_name;
    char *description;
    int damage;
    int cost;
    int n_targets;
    int effect_id;
} Spell;

Spell *create_spell(int id, char *spell_name, char *description, int damage, int cost, int n_targets, int effect_id);
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
