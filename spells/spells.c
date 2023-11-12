/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"
#include "../headers/spells.h"


Spell *create_spell(int id, char *spell_name, char *description, int damage, int cost, int n_targets, int effect_id)
{
    // allocate memory for a new spell struct
    Spell *new_spell = malloc(sizeof(Spell));

    // assign values to the fields of the new spell
    new_spell->id = id;
    new_spell->spell_name = strdup(spell_name);
    new_spell->description = strdup(description);
    new_spell->damage = damage;
    new_spell->cost = cost;
    new_spell->n_targets = n_targets;
    new_spell->effect_id =effect_id;

    // return the newly created spell
    return new_spell;
}

Spell*spell_from_csv(int index)
{
    FILE *file = fopen("csv_files/spells/spells.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; char spell_name[50]; char description[50]; int damage; int cost; int n_targets; int effect_id;

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d,%d", &id, spell_name, description, &damage, &cost, &n_targets, &effect_id) == 7)
            {
                fclose(file);
                return create_spell(id, spell_name, description, damage, cost, n_targets, effect_id);
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


char*name_effect(int index)
{
    FILE *file = fopen("csv_files/spells/effects.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int duration; int damage; int damage_reduction; int defense_reduction; int freeze;
            char *name = (char *)malloc(50 * sizeof(char));
            char *description = (char *)malloc(50 * sizeof(char));

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d,%d,%d,%d", &id, name, description, &duration, &damage, &damage_reduction, &defense_reduction, &freeze) == 8)
            {
                fclose(file);
                return name;

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

char*description_effect(int index)
{
    FILE *file = fopen("csv_files/spells/effects.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int duration; int damage; int damage_reduction; int defense_reduction; int freeze;
            char *name = (char *)malloc(50 * sizeof(char));
            char *description = (char *)malloc(50 * sizeof(char));

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d,%d,%d,%d", &id, name, description, &duration, &damage, &damage_reduction, &defense_reduction, &freeze) == 8)
            {
                fclose(file);
                return description;

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

int stat_effect(int index, char*stat)
{
    FILE *file = fopen("csv_files/spells/effects.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int duration; int damage; int damage_reduction; int defense_reduction; int freeze;
            char *name = (char *)malloc(50 * sizeof(char));
            char *description = (char *)malloc(50 * sizeof(char));

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d,%d,%d,%d", &id, name, description, &duration, &damage, &damage_reduction, &defense_reduction, &freeze) == 8)
            {
                fclose(file);
                if(stat=="duration")
                {
                    return duration;
                }
                if(stat=="damage")
                {
                    return damage;
                }
                if(stat=="damage_reduction")
                {
                    return damage_reduction;
                }
                if(stat=="defense_reduction")
                {
                    return defense_reduction;
                }
                if(stat=="freeze")
                {
                    return freeze;
                }

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

void diplay_player_spells(Character*player)
{

}
