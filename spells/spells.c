#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"
#include "../headers/spells.h"


char *get_offensive(Character *character) {

    if (character->offensive_spell == NULL || character->offensive_spell->spell_name == NULL) {
        return strdup("No offensive spell");
    } else {
        return strdup(character->offensive_spell->spell_name);
    }

}

void set_offensive(Character *character, char *selection) {

    if (strcmp(selection, "Dragon Breath") == 0) {
        system("clear");
        if (character->offensive_spell->spell_name != NULL) {
            free(character->offensive_spell->spell_name);
        }
        character->offensive_spell->spell_name = malloc(strlen("Dragon Breath") + 1);
        if (character->offensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->offensive_spell->spell_name, "Dragon Breath");
    }

    if (strcmp(selection, "Eat This") == 0) {
        system("clear");
        if (character->offensive_spell->spell_name != NULL) {
            free(character->offensive_spell->spell_name);
        }
        character->offensive_spell->spell_name = malloc(strlen("Eat This") + 1);
        if (character->offensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->offensive_spell->spell_name, "Eat This");
    }

    if (strcmp(selection, "Lightning Chain") == 0) {
        system("clear");
        if (character->offensive_spell->spell_name != NULL) {
            free(character->offensive_spell->spell_name);
        }
        character->offensive_spell->spell_name = malloc(strlen("Lightning Chain") + 1);
        if (character->offensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->offensive_spell->spell_name, "Lightning Chain");
    }

    printf("%s changed the offensive spell to %s\n", character->username, get_offensive(character));
}

void select_offensive_spell(Character *character) {
    system("clear");

    char *offensiveSpell[] = {"Dragon Breath", "Eat This", "Lightning Chain"};
    int quantity = sizeof(offensiveSpell) / sizeof(offensiveSpell[0]);

    char *offensive_spell = get_offensive(character);
    printf("Your current offensive spell : %s\n", offensive_spell);
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, offensiveSpell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter Your Choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= quantity) {
        // printf("%s", offensiveSpell[choice - 1]);
        set_offensive(character, offensiveSpell[choice - 1]);
        offensive_spell = get_offensive(character);
    } else if (choice != 0) {
        printf("invalid choice: %d\n", choice);
    }

    free(offensive_spell);
}

char *get_defensive(Character *character) {

    if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
        return strdup("No defensive spell");
    } else {
        return strdup(character->defensive_spell->spell_name);
    }

}

void set_defensive(Character *character, char *selection) {

    if (strcmp(selection, "Dragon Skin") == 0) {
        system("clear");
        if (character->defensive_spell->spell_name != NULL) {
            free(character->defensive_spell->spell_name);
        }
        character->defensive_spell->spell_name = malloc(strlen("Dragon Skin") + 1);
        if (character->defensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->defensive_spell->spell_name, "Dragon Skin");
    }

    if (strcmp(selection, "Protected Area") == 0) {
        system("clear");
        if (character->defensive_spell->spell_name != NULL) {
            free(character->defensive_spell->spell_name);
        }
        character->defensive_spell->spell_name = malloc(strlen("Protected Area") + 1);
        if (character->defensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->defensive_spell->spell_name, "Protected Area");
    }

    if (strcmp(selection, "Stick To Me") == 0) {
        system("clear");
        if (character->defensive_spell->spell_name != NULL) {
            free(character->defensive_spell->spell_name);
        }
        character->defensive_spell->spell_name = malloc(strlen("Stick To Me") + 1);
        if (character->defensive_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->defensive_spell->spell_name, "Stick To Me");
    }

    printf("%s changed the defensive spell to %s\n", character->username, get_defensive(character));
}

void select_defensive_spell(Character *character) {
    system("clear");

    char *defensiveSpell[] = {"Dragon Skin", "Protected Area", "Stick To Me"};
    int quantity = sizeof(defensiveSpell) / sizeof(defensiveSpell[0]);

    char *defensive_spell = get_defensive(character);
    printf("Your current offensive spell : %s\n", defensive_spell);
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, defensiveSpell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter Your Choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= quantity) {
        // printf("%s", defensiveSpell[choice - 1]);
        set_defensive(character, defensiveSpell[choice - 1]);
        defensive_spell = get_defensive(character);
    } else if (choice != 0) {
        printf("invalid choice: %d\n", choice);
    }

    free(defensive_spell);
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
            select_defensive_spell(character);
            break;
        case 3:
            system("clear");
            break;
        default:
            system("clear");
            printf("\nChoose between 0 and 4 !\n");
    }
}
