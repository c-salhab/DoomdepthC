/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#ifndef DOOMDEPTHC_GEAR_H
#define DOOMDEPTHC_GEAR_H

#include "weapon.h"
#include "armor.h"

typedef struct {
     Weapon *equipped_weapon;
     Armor *equipped_armor;
} Gear;

#endif //DOOMDEPTHC_GEAR_H
