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

    char *offensive_spell[] = {"Dragon Breath", "Eat This", "Lightning Chain"};
    int quantity = sizeof(offensive_spell) / sizeof(offensive_spell[0]);

    char *offensive = get_offensive(character);
    printf("Your current offensive spell : %s\n", offensive);
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, offensive_spell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= quantity) {
        // printf("%s", offensiveSpell[choice - 1]);
        set_offensive(character, offensive_spell[choice - 1]);
        offensive = get_offensive(character);
    } else if (choice != 0) {
        printf("invalid choice: %d\n", choice);
    }

    free(offensive);
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

    char *defensive_spell[] = {"Dragon Skin", "Protected Area", "Stick To Me"};
    int quantity = sizeof(defensive_spell) / sizeof(defensive_spell[0]);

    char *defensive = get_defensive(character);
    printf("Your current defensive spell : %s\n", defensive);
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, defensive_spell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= quantity) {
        // printf("%s", defensive_spell[choice - 1]);
        set_defensive(character, defensive_spell[choice - 1]);
        defensive = get_defensive(character);
    } else if (choice != 0) {
        printf("invalid choice: %d\n", choice);
    }

    free(defensive);
}

char *get_heal(Character *character) {

    if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
        return strdup("No heal spell");
    } else {
        return strdup(character->heal_spell->spell_name);
    }

}

void set_heal(Character *character, char *selection) {

    if (strcmp(selection, "Healing Aura") == 0) {
        system("clear");
        if (character->heal_spell->spell_name != NULL) {
            free(character->heal_spell->spell_name);
        }
        character->heal_spell->spell_name = malloc(strlen("Healing Aura") + 1);
        if (character->heal_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->heal_spell->spell_name, "Healing Aura");
    }

    if (strcmp(selection, "Healing Light House") == 0) {
        system("clear");
        if (character->heal_spell->spell_name != NULL) {
            free(character->heal_spell->spell_name);
        }
        character->heal_spell->spell_name = malloc(strlen("Healing Light House") + 1);
        if (character->heal_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->heal_spell->spell_name, "Healing Light House");
    }

    if (strcmp(selection, "Heart Of Dragon") == 0) {
        system("clear");
        if (character->heal_spell->spell_name != NULL) {
            free(character->heal_spell->spell_name);
        }
        character->heal_spell->spell_name = malloc(strlen("Heart Of Dragon") + 1);
        if (character->heal_spell->spell_name == NULL) {
            exit(1);
        }
        strcpy(character->heal_spell->spell_name, "Heart Of Dragon");
    }

    printf("%s changed the heal spell to %s\n", character->username, get_heal(character));
}

void select_heal_spell(Character *character) {
    system("clear");

    char *heal_spell[] = {"Healing Aura", "Healing Light House", "Heart Of Dragon"};
    int quantity = sizeof(heal_spell) / sizeof(heal_spell[0]);

    char *heal = get_heal(character);
    printf("Your current heal spell : %s\n", heal);
    printf("\n");

    for (int i = 0; i < quantity; i++) {
        printf("%d. %s\n", i + 1, heal_spell[i]);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= quantity) {
        // printf("%s", heal_spell[choice - 1]);
        set_heal(character, heal_spell[choice - 1]);
        heal = get_heal(character);
    } else if (choice != 0) {
        printf("invalid choice: %d\n", choice);
    }

    free(heal);
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
            select_heal_spell(character);
            break;
        default:
            system("clear");
            printf("\nChoose between 0 and 4 !\n");
    }
}
