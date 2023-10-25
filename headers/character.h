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
char offensive_spell;
char defensive_spell;
char heal_spell;

Character *init_character(char *name);

void show_specs(Character *character);

int has_inventory(Character *character);

int has_spells(Character *character);

void set_weapon(Character *character, Weapon *selection);

void takes_weapon(Character *character, int weapon);

void set_offensive_spells(Character *character, Spell *offensive_spell);

void takes_offensive_spells(Character *character, int offensive);

void set_defensive_spells(Character *character, Spell *selection);

void takes_defensive_spells(Character *character, int defensive);

void set_heal_spells(Character *character, Spell *selection);

void takes_heal_spells(Character *character, int heal);

void set_armor(Character *character, Armor *selection);

void takes_armor(Character *character, int armor);

void takes_inventory(Character *character);

void takes_spells(Character *character);

void check_inventory(Character *character);

void character_attack(Character *character, Monster *monster);

void monster_attack(Character *character, Monster *monster);

void has_leveled_up(Character *character);

void gain_exp(Character *character);

void restore(Character *character);

void fight(Character *character, Monster **list_monsters, int num_monsters);

#endif