/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdlib.h>
#include <string.h>
#include "../headers/weapon.h"

/*
 * the strdup() function is used to create a new string by duplicating an existing string.
 * it allocates memory for the new string and copies the contents of the original string into the newly allocated memory.
 * this is particularly useful when you want to create a copy of a string to avoid any unintentional modification of the original string.
 */

Weapon *create_weapon(char *type, char *weapon_name, char *description, float physical_damage, float durability) {
    // allocate memory for a new Weapon struct
    Weapon *new_weapon = malloc(sizeof(Weapon));

    // copy the provided strings into the allocated memory
    new_weapon->type = strdup(type);
    new_weapon->weapon_name = strdup(weapon_name);
    new_weapon->description = strdup(description);

    // assign the provided values to the physical_damage and durability fields
    new_weapon->physical_damage = physical_damage;
    new_weapon->durability = durability;

    // return the new weapon created
    return new_weapon;
}
