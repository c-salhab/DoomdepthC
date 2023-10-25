/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdlib.h>
#include <string.h>
#include "../headers/armor.h"

Armor *create_armor(char *armor_name, char *description, float physical_defense, int durability) {
    Armor *new_armor = malloc(sizeof(Armor));
    new_armor->armor_name = strdup(armor_name);
    new_armor->description = strdup(description);
    new_armor->physical_defense = physical_defense;
    new_armor->durability = durability;
    return new_armor;
}






