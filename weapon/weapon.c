/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdlib.h>
#include <string.h>
#include "../headers/weapon.h"

Weapon *create_weapon(char *type, char *weapon_name, char *description, float physical_damage, float magical_damage, float durability) {
    Weapon *new_weapon = malloc(sizeof(Weapon));
    new_weapon->type = strdup(type);
    new_weapon->weapon_name = strdup(weapon_name);
    new_weapon->description = strdup(description);
    new_weapon->physical_damage = physical_damage;
    new_weapon->magical_damage = magical_damage;
    new_weapon->durability = durability;
    return new_weapon;
}
