/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_INVENTORY_H
#define DOOMDEPTHC_INVENTORY_H

int MAX_WEAPONS = 5;
int MAX_ARMORS = 5;

#include "weapon.h"
#include "armor.h"

typedef struct {
     Weapon *equipped_weapon;
     Armor *equipped_armor;
    Weapon **weapons;
    int num_weapons;
    Armor **armors;
    int num_armors;
} Inventory;

#endif //DOOMDEPTHC_INVENTORY_H
