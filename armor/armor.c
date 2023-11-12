/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/armor.h"

Armor *create_armor(int id, char *armor_name, char *description, int physical_defense, int durability, int level)
{
    // allocate memory for a new armor
    Armor *new_armor = malloc(sizeof(Armor));

    // set the properties of the new armor

    new_armor->id=id;
    // duplicate and store the armor name
    new_armor->armor_name = strdup(armor_name);
    // duplicate and store the description
    new_armor->description = strdup(description);
    // set the physical defense value
    new_armor->physical_defense = physical_defense;
    // set the durability value
    new_armor->durability = durability;

    new_armor->level = level;

    // return a pointer to the newly created armor
    return new_armor;
}

void armor_stat(Armor*armor)
{
    printf("\n------- %s -------\n\n",armor->armor_name);
    printf("Level: %d\n",armor->level);
    printf("Armor: %d\n",armor->physical_defense);
    printf("Durability: %d\n",armor->durability);
    printf("\n%s\n",armor->description);
    printf("\n------------------\n\n");
}



Armor*armor_from_csv(int index)
{
    FILE *file = fopen("csv_files/armors.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int physical_defense; int durability; int level;
            char armor_name[50]; char description[50];

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d", &id, armor_name, description, &physical_defense, &durability, &level) == 6)
            {
                fclose(file);
                return create_armor(id,armor_name,description,physical_defense,durability,level);
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




