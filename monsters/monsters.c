/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/monsters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

Monster*init_monster(int id,char*name, int life, int min_power, int max_power, int defense, int level) {
    // allocate memory for a new Monster
    Monster * monster = malloc(sizeof(Monster));

    // assign the provided values to the Monster's attributes
    monster->id = id;
    
    monster->name=malloc(sizeof(char)*strlen(name));
    strcpy(monster->name,name);

    monster->life = life;
    monster->min_power = min_power;
    monster->max_power = max_power;
    monster->defense = defense;
    monster->level = level;

    return monster;

}

void print_monster_stat(Monster*monster)
{
    printf("Name: %s\n",monster->name);
    printf("Level: %d\n",monster->level);
    printf("Life: %d\n",monster->life);
    printf("Max Power: %d\n",monster->max_power);
    printf("Min Power: %d\n",monster->min_power);
}


Monster*read_monster_from_csv(const char *filename, int index) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id, life, min_power, max_power, defense, level;
            char name[50];

            if (sscanf(line, "%d,%49[^,],%d,%d,%d,%d,%d", &id, name, &life, &min_power, &max_power, &defense, &level) == 7) {
                fclose(file);
                return init_monster(id, name, life, min_power, max_power, defense, level);
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

int monster_is_alive(Monster*monster)
{
    return monster->life > 0;
}
