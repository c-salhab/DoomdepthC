/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_WEAPON_H
#define DOOMDEPTHC_WEAPON_H

typedef struct{
    char *type;
    char *weapon_name;
    char *description;
    float physical_damage;
    float magical_damage;
    float durability;
} Weapon;

Weapon *create_weapon(char *type, char *weapon_name, char *description, float physical_damage, float magical_damage, float durability);

#endif //DOOMDEPTHC_WEAPON_H
