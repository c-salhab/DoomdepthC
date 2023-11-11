/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdlib.h>
#include <string.h>
#include "../headers/armor.h"

Armor *create_armor(char *armor_name, char *description, float physical_defense, int durability) {
    // allocate memory for a new armor
    Armor *new_armor = malloc(sizeof(Armor));

    // set the properties of the new armor
    // duplicate and store the armor name
    new_armor->armor_name = strdup(armor_name);
    // duplicate and store the description
    new_armor->description = strdup(description);
    // set the physical defense value
    new_armor->physical_defense = physical_defense;
    // set the durability value
    new_armor->durability = durability;

    // return a pointer to the newly created armor
    return new_armor;
}






