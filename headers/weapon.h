/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_WEAPON_H
#define DOOMDEPTHC_WEAPON_H

typedef struct{
    int id;
    char *type;
    char *weapon_name;
    char *description;
    int physical_damage;
    int durability;
    int level;
} Weapon;

Weapon *create_weapon(int id, char *type, char *weapon_name, char *description, int physical_damage, int durability, int level);

#endif //DOOMDEPTHC_WEAPON_H

