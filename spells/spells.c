#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"
#include "../headers/spells.h"


char *get_offensive(Character *character) {
    char *buffer = malloc(512);

    //if (character->offensive_spell != NULL) {
    //    strcpy(buffer, character->offensive_spell->spell_name);
    strcat(buffer, " (Your current offensive spell)");
    //} else {
    strcpy(buffer, "No offensive spell");
    //}

    return buffer;
}

void set_offensive(Character *character, char *selection) {
    if (strcmp(selection, "Eat This") == 0) {
        system("clear");
        // Allouer de la mémoire pour spell_name
        character->offensive_spell->spell_name = malloc(strlen("Eat This") + 1);
        // Copier la chaîne littérale dans spell_name
        strcpy(character->offensive_spell->spell_name, "Eat This");
        printf("%s changed the offensive spell to %s\n\n", character->username, get_offensive(character));
    } else {
        printf("Unknown selection: %s\n", selection);
    }
}

void select_offensive_spell(Character *character) {
    system("clear");

    char *offensiveSpell[] = {"Dragon Breath", "Eat This", "Lightning Chain"};
    int quantity = sizeof(offensiveSpell) / sizeof(offensiveSpell[0]);

    printf("Your current offensive spell : %s\n", get_offensive(character));
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, offensiveSpell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter Your Choice (or 0 to cancel): ");
    scanf("%d", &choice);

    char *selection = malloc(sizeof(char *) * 100);
    if(choice >= 1 && choice <= quantity){
       selection = offensiveSpell[choice - 1];
    }

    set_offensive(character, selection);

}


void choose_another_spell(Character *character){
    system("clear");

    printf("\x1b[34m");
    printf("\nMenu\n");
    printf("\x1b[0m");

    printf("1. Choose an Offensive Spell\n");
    printf("2. Choose a Defensive Spell\n");
    printf("3. Choose a Heal Spell\n");
    printf("0. Cancel\n");

    printf("\n");
    int choice;

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 0:
            system("clear");
            break;
        case 1:
            system("clear");
            select_offensive_spell(character);
            break;
        case 2:
            system("clear");
            break;
        case 3:
            system("clear");
            break;
        default:
            system("clear");
            printf("\nChoose between 0 and 4 !\n");
    }
}
