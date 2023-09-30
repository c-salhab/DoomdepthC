/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef SPELLS_H
#define SPELLS_H

typedef struct {
    char * spell_name;
    char * description;
    char *type;
    int cost;
    int physical_damage;
    int magical_damage;
} Spell;

void choose_another_spell(Character *character);
#endif