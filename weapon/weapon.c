/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/weapon.h"

/*
 * the strdup() function is used to create a new string by duplicating an existing string.
 * it allocates memory for the new string and copies the contents of the original string into the newly allocated memory.
 * this is particularly useful when you want to create a copy of a string to avoid any unintentional modification of the original string.
 */

Weapon *create_weapon(int id, char *type, char *weapon_name, char *description, int physical_damage, int durability, int level) {
    // allocate memory for a new Weapon struct
    Weapon *new_weapon = malloc(sizeof(Weapon));

    // copy the provided strings into the allocated memory
    new_weapon->id = id;
    new_weapon->type = strdup(type);
    new_weapon->weapon_name = strdup(weapon_name);
    new_weapon->description = strdup(description);

    // assign the provided values to the physical_damage and durability fields
    new_weapon->physical_damage = physical_damage;
    new_weapon->durability = durability;
    new_weapon->level = level;

    // return the new weapon created
    return new_weapon;
}


void weapon_stat(Weapon*weapon)
{
    printf("\n------- %s -------\n\n",weapon->weapon_name);
    printf("Level: %d\n",weapon->level);
    printf("Damage: %d\n",weapon->physical_damage);
    printf("Durability: %d\n",weapon->durability);
    printf("\n%s\n",weapon->description);
    printf("\n------------------\n\n");
}


Weapon*weapon_from_csv(int index) 
{
    FILE *file = fopen("csv_files/weapons.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int physical_damage; int durability; int level;
            char type[50]; char weapon_name[50]; char description[50];

            if (sscanf(line, "%d,%49[^,],%49[^,],%49[^,],%d,%d,%d", &id, type, weapon_name, description, &physical_damage, &durability, &level) == 7) 
            {
                fclose(file);
                return create_weapon(id,type,weapon_name,description,physical_damage,durability,level);
            } else {
                fclose(file);
                perror("Error parsing CSV line");
                exit(EXIT_FAILURE);
            }
        }

        current_index+=1;
    }

    fclose(file);
}


