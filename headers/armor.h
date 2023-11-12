/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_ARMOR_H
#define DOOMDEPTHC_ARMOR_H

typedef struct{
    int id;
    char *armor_name;
    char *description;
    float physical_defense;
    int durability;
    int level;
} Armor;

Armor *create_armor(int id, char *armor_name, char *description, int physical_defense, int durability, int level);

#endif //DOOMDEPTHC_ARMOR_H
