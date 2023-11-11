/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_ARMOR_H
#define DOOMDEPTHC_ARMOR_H

typedef struct{
    char *armor_name;
    char *description;
    float physical_defense;
    int durability;
} Armor;

Armor *create_armor(char *armor_name, char *description, float physical_defense, int durability);

#endif //DOOMDEPTHC_ARMOR_H
