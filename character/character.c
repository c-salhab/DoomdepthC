/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"
#include "../headers/monsters.h"
#include "../weapon/weapon.c"
#include "../armor/armor.c"
#include "../headers/spells.h"
#include <ctype.h>

// declaration and initialization of character variables with null character
char offensive_spell = '\0'; // represents an offensive spell
char defensive_spell = '\0'; // represents a defensive spell
char heal_spell = '\0'; // represents a healing spell

Character *init_character(char *name) {
    // allocate memory for a new character
    Character *character = malloc(sizeof(Character));
    // set the username of the character to the provided name
    character->username = name;

    // set the current health to the maximum health
    character->current_health = 100;
    // set the current mana to the maximum mana
    character->current_mana = 100;

    // set the level to 1
    character->level = 1;
    // set the initial experience points to 0
    character->exp = 0;

    // set the initial gold amount to 0
    character->gold = 0;
    // initialize the offensive spell as null

    character->offensive_spell = NULL;
    // initialize the heal spell as null
    character->heal_spell = NULL;

    // allocate memory for the character's inventory
    character->inventory = (Inventory *)malloc(sizeof(Inventory));
    // initialize the equipped weapon and armor in the character's inventory as null
    character->inventory->equipped_weapon = NULL;
    character->inventory->equipped_armor = NULL;

    character->inventory->num_armors = 0;

    character->inventory->num_weapons = 0;
    MAX_ARMORS = 10;
    MAX_WEAPONS = 10;
    character->inventory->weapons = malloc(MAX_WEAPONS * sizeof(Weapon*));
    character->inventory->armors = malloc(MAX_ARMORS * sizeof(Armor*));

    for (int i = 0; i < MAX_ARMORS; i++) {
        character->inventory->armors[i] = NULL;
    }

    for (int i = 0; i < MAX_WEAPONS; i++) {
        character->inventory->weapons[i] = NULL;
    }

    // return a pointer to the newly created character
    return character;
}

void set_equipped_armor(Character *character, Armor *selection) {
    // free the memory of the previously equipped armor if it exists
    if (character->inventory->equipped_armor != NULL) {
        free(character->inventory->equipped_armor->armor_name);
        free(character->inventory->equipped_armor);
    }

    // allocate memory for the new equipped armor
    character->inventory->equipped_armor = (Armor *)malloc(sizeof(Armor));

    // copy the attributes of the provided armor to the character's equipped armor
    character->inventory->equipped_armor->armor_name = strdup(selection->armor_name);
    character->inventory->equipped_armor->description = selection->description;
    character->inventory->equipped_armor->physical_defense = selection->physical_defense;
    character->inventory->equipped_armor->durability = selection->durability;
}

void set_equipped_weapon(Character *character, Weapon *selection) {
    // free memory of the previously equipped weapon if it exists
    if (character->inventory->equipped_weapon != NULL) {
        free(character->inventory->equipped_weapon->weapon_name);
        free(character->inventory->equipped_weapon->description);
        free(character->inventory->equipped_weapon);
    }

    // allocate memory for the new equipped weapon
    character->inventory->equipped_weapon = (Weapon *)malloc(sizeof(Weapon));

    // copy the attributes of the selected weapon to the equipped weapon
    character->inventory->equipped_weapon->type = strdup(selection->type);
    character->inventory->equipped_weapon->weapon_name = strdup(selection->weapon_name);
    character->inventory->equipped_weapon->description = strdup(selection->description);
    character->inventory->equipped_weapon->physical_damage = selection->physical_damage;
    character->inventory->equipped_weapon->durability = selection->durability;
}

void choose_from_inventory(Character *character) {

    int choice;
    int max_armor_choice = character->inventory->num_armors;
    int max_weapon_choice = character->inventory->num_weapons;

    printf("\x1b[34m");
    printf("\nEquip from inventory\n");
    printf("\x1b[0m");

    printf("1. Armors\n");
    printf("2. Weapons\n");
    printf("0. Cancel\n");

    printf("\x1b[32m");
    printf("\nEnter your choice : ");
    printf("\x1b[0m");

    scanf("%d", &choice);

    switch (choice) {
        case 0:
            system("clear");
            break;
        case 1:
            system("clear");

            printf("\x1b[34m");
            printf("\nArmors\n");
            printf("\x1b[0m");

            int found = 0;

            for (int i = 0; i < character->inventory->num_armors; i++) {
                if (character->inventory->armors[i] != NULL) {
                    found = 1;
                    printf("%d. %s\n", i + 1, character->inventory->armors[i]->armor_name);
                }
            }

            if (!found) {
                printf("No armors\n");
                break;
            }else{
                printf("0. Cancel\n");
            }

            printf("\x1b[32m");
            printf("\nEnter your choice : ");
            printf("\x1b[0m");

            scanf("%d", &choice);

            if (choice == 0) {
                system("clear");
                break;
            }

            set_equipped_armor(character, character->inventory->armors[choice - 1]);

            break;

        case 2:
            system("clear");

            printf("\x1b[34m");
            printf("\nWeapons\n");
            printf("\x1b[0m");

            int found_weapon = 0;

            for (int i = 0; i < character->inventory->num_weapons; i++) {
                if (character->inventory->weapons[i] != NULL) {
                    found_weapon = 1;
                    printf("%d. %s\n", i + 1, character->inventory->weapons[i]->weapon_name);
                }
            }

            if (!found_weapon) {
                printf("No weapons\n");
                break;
            }else{
                printf("0. Cancel\n");
            }

            printf("\x1b[32m");
            printf("\nEnter your choice : ");
            printf("\x1b[0m");

            scanf("%d", &choice);

            if (choice == 0) {
                system("clear");
                break;
            }

            set_equipped_weapon(character, character->inventory->weapons[choice - 1]);

            break;


        default:
            printf("You have to choose between 0 and 2!\n");
            break;
    }

}


void show_specs(Character *character){

    printf("\n");

    // print a line of 'X' characters for visual separation
    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");

    // print a header with information about the character
    char *str = "Informations on the Character ";
    int size = strlen(str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("%s", str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("\n");

    // display various details about the character
    printf("Username : %s\n", character->username);
    printf("Gold : %d\n", character->gold);
    printf("Character's Level : %d\n", character->level);
    printf("Xp [%d/%d] : ", character->exp, exp_needed_to_level_up);

    int current_xp_indication = (character->exp * 30) / exp_needed_to_level_up;

    printf("[");
    for(int i = 0; i < current_xp_indication; i++){
        printf("#");
    }
    printf("]\n");

    // print a header for displaying the statistics
    str = "The stats : ";
    size = strlen(str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("%s", str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("\n");

    // display the current health and mana of the character
    if(character->current_health < 0){
        printf("Life : 00.00\n");
    }else{
        printf("Life : %.2f\n", character->current_health);
    }

    if(character->current_mana < 0){
        printf("Mana : 00.00\n");
    }else{
        printf("Mana : %.2f\n", character->current_mana);
    }

    // print a header for displaying the character's spells
    str = "Spells : ";
    size = strlen(str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("%s", str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("\n");

    str = "Inventory : ";
    size = strlen(str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("%s", str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }
    printf("\n");

    // display the equipped weapon and armor in the character's inventory
    printf("Equipped Weapon : ");
    if (character->inventory == NULL || character->inventory->equipped_weapon == NULL) {
        printf("No equipped weapon\n");
    } else {
        printf("%s\n", character->inventory->equipped_weapon->weapon_name);
    }
    printf("Equipped Armor : ");
    if (character->inventory == NULL || character->inventory->equipped_armor == NULL) {
        printf("No equipped armor\n");
    } else {
        printf("%s\n", character->inventory->equipped_armor->armor_name);
    }

    printf("\n");

    // display armors
    if (character->inventory->num_armors == 0) {
        printf("Armors (Capacity : %d):\nNo armors\n", MAX_ARMORS - 1);
    } else {
        printf("Armors (Capacity : %d):\n", MAX_ARMORS - 1);
        int found_armor = 0;
        for (int i = 0; i < character->inventory->num_armors; i++) {
            if (character->inventory->armors[i] != NULL) {
                found_armor = 1;
                printf("%d. %s\n", i + 1, character->inventory->armors[i]->armor_name);
            }
        }

        if (!found_armor) {
            printf("No armors\n");
        }
    }

    printf("\n");

    // display weapons
    if (character->inventory->num_weapons == 0) {
        printf("Weapons (Capacity : %d):\nNo weapons\n", MAX_WEAPONS - 1);
    } else {
        printf("Weapons (Capacity : %d):\n", MAX_WEAPONS - 1);
        int found_weapon = 0;

        for (int i = 0; i < character->inventory->num_weapons; i++) {
            if (character->inventory->weapons[i] != NULL) {
                found_weapon = 1;
                printf("%d. %s\n", i + 1, character->inventory->weapons[i]->weapon_name);
            }
        }

        if (!found_weapon) {
            printf("No weapons\n");
        }
    }


    // print a line of X characters for visual separation
    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");
}

int has_inventory(Character *character) {
    // check if the character's inventory has no equipped weapon or armor
    if (character->inventory->equipped_weapon == NULL || character->inventory->equipped_armor == NULL) {
        return 1; // return 1 if the inventory has no equipped weapon or armor
    } else {
        return 0; // return 0 if the inventory has equipped weapon or armor
    }
}

int has_spells(Character *character) {
    // check if the character has no defensive, offensive, or healing spells
    if (character->offensive_spell == NULL || character->heal_spell == NULL) {
        return 1; // return 1 if the character has no defensive, offensive, or healing spells
    } else {
        return 0; // return 0 if the character has at least one defensive, offensive, or healing spell
    }
}


void remove_weapon(Character *character, Weapon *weapon) {
    int i;
    int found = 0;

    for (i = 0; i < character->inventory->num_weapons; i++) {
        if(strcmp(character->inventory->weapons[i]->weapon_name, weapon->weapon_name) == 0 && !found){
            character->inventory->weapons[i] = NULL;
            found = 1;
        }
    }

    if (character->inventory->equipped_weapon == weapon) {
        free(character->inventory->equipped_weapon->weapon_name);
        free(character->inventory->equipped_weapon->description);
        free(character->inventory->equipped_weapon->type);
        free(character->inventory->equipped_weapon);
        character->inventory->equipped_weapon = NULL;
    }
}

void remove_armor(Character *character, Armor *armor) {
    int i;
    int found = 0;

    for (i = 0; i < character->inventory->num_armors; i++) {
        if(strcmp(character->inventory->armors[i]->armor_name, armor->armor_name) == 0 && !found){
            character->inventory->armors[i] = NULL;
            found = 1;
        }
    }

    if (character->inventory->equipped_armor == armor) {
        free(character->inventory->equipped_armor->armor_name);
        free(character->inventory->equipped_armor->description);
        free(character->inventory->equipped_armor);
        character->inventory->equipped_armor = NULL;
    }
}



int player_is_alive(Character*player)
{
    return player->current_health > 0;
}


void has_leveled_up(Character *character){
    // increase the character's level by 1
    character->level += 1;
    // reset the character's experience to 0
    character->exp = 0;
    // increase the experience needed to level up for the next level
    exp_needed_to_level_up *= 1.5;

    // increase the character's current health and mana by 50%
    character->current_health += character->current_health * 1.5;
    character->current_mana += character->current_mana * 1.5;

    // increase the maximum health and mana by 50%
    max_health += character->current_health;
    max_mana += character->current_mana;
    MAX_WEAPONS += 2;
    MAX_ARMORS += 2;

    printf("\n%s has leveled up !\n", character->username);
    printf("%s is level %d !\n", character->username, character->level);
}

void gain_exp(Character *character){
    // define a ratio for the experience gain
    float ratio = 1.5;

    // increase the character's experience by 25 times the defined ratio
    character->exp += 25 * ratio;

    // check if the character's experience is greater than or equal to the required experience to level up
    if (character->exp >= exp_needed_to_level_up) {
        // call the has_leveled_up function to handle level-up logic
        has_leveled_up(character);
    }
}

void restore(Character *character){
    // restore the character's health and mana to their maximum values
    character->current_health = max_health;
    character->current_mana = max_mana;

}
