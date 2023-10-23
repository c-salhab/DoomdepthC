/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"

Spell *create_spell(char *spell_name, int cost, int physical_damage, int magical_damage) {

    Spell *new_spell = malloc(sizeof(Spell));
    new_spell->spell_name = strdup(spell_name);
    new_spell->cost = cost;
    new_spell->physical_damage = physical_damage;
    new_spell->magical_damage = magical_damage;

    return new_spell;
}

char *get_offensive(Character *character) {

    if (character->offensive_spell == NULL) {
        return "No offensive spell";
    } else {
        return character->offensive_spell->spell_name;
    }

}

void set_offensive(Character *character, Spell *selection) {
    if (character->offensive_spell != NULL) {
        free(character->offensive_spell->spell_name);
        free(character->offensive_spell);
    }

    character->offensive_spell = (Spell*)malloc(sizeof(Spell));
    character->offensive_spell->spell_name = strdup(selection->spell_name);
    character->offensive_spell->cost = selection->cost;
    character->offensive_spell->physical_damage = selection->physical_damage;
    character->offensive_spell->magical_damage = selection->magical_damage;

    printf("%s changed the offensive spell to %s\n", character->username, character->offensive_spell->spell_name);
}

void select_offensive_spell(Character *character) {
    system("clear");

    Spell *dragon_breath = create_spell("Dragon Breath", 100, 0, 500);
    Spell *eat_this = create_spell("Eat This", 65, 0 , 300);
    Spell *lightning_chain = create_spell("Lightning Chain", 65, 0, 300);

    Spell *can_use[3];
    can_use[0] = dragon_breath;
    can_use[1] = eat_this;
    can_use[2] = lightning_chain;

    char *offensive = get_offensive(character);
    printf("Your current offensive spell : %s\n", offensive);
    printf("\n");

    printf("\x1b[33m");
    printf("Your current gold balance is: %d gold coins\n", character->gold);
    printf("\x1b[0m\n");

    printf("\x1b[31m");
    printf("Each offensive spell costs 20 gold coins\n\n");
    printf("\x1b[0m");

    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, can_use[i]->spell_name);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= 3) {

        if(character->gold >= 20){

            if (character->offensive_spell == NULL || character->offensive_spell->spell_name == NULL) {
                // printf("test ok");
                character->gold = character->gold - 20;
                // printf("%s", can_use[choice - 1]->spell_name);
                set_offensive(character, can_use[choice - 1]);
            } else {
                if (strcmp(can_use[choice - 1]->spell_name, character->offensive_spell->spell_name) == 0) {
                    // printf("test ok");
                    system("clear");
                    printf("%s already has the offensive spell %s\n", character->username,can_use[choice - 1]->spell_name);
                } else {
                    // printf("test ok");
                    character->gold = character->gold - 20;
                    //printf("%s", can_use[choice - 1]->spell_name);
                    set_offensive(character, can_use[choice - 1]);
                }
            }


        }else{
            printf("Insufficient gold coins to make the purchase !\n");
        }

    } else if (choice != 0) {
        printf("Invalid choice : %d\n", choice);
    }

    free(dragon_breath->spell_name);
    free(dragon_breath);
    free(eat_this->spell_name);
    free(eat_this);
    free(lightning_chain->spell_name);
    free(lightning_chain);
}

char *get_defensive(Character *character) {

    if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
        return "No defensive spell";
    } else {
        return character->defensive_spell->spell_name;
    }

}

void set_defensive(Character *character, Spell *selection) {

    if (character->defensive_spell != NULL) {
        free(character->defensive_spell->spell_name);
        free(character->defensive_spell);
    }

    character->defensive_spell = (Spell*)malloc(sizeof(Spell));
    character->defensive_spell->spell_name = strdup(selection->spell_name);
    character->defensive_spell->cost = selection->cost;
    character->defensive_spell->physical_damage = selection->physical_damage;
    character->defensive_spell->magical_damage = selection->magical_damage;

    printf("%s changed the defensive spell to %s\n", character->username, get_defensive(character));
}

void select_defensive_spell(Character *character) {
    system("clear");

    Spell *dragon_skin = create_spell("Dragon Skin", 40, 40, 200);
    Spell *protected_area = create_spell("Protected Area", 40, 150 , 100);
    Spell *stick_to_me = create_spell("Stick To Me", 100, 120, 300);

    Spell *can_use[3];
    can_use[0] = dragon_skin;
    can_use[1] = protected_area;
    can_use[2] = stick_to_me;

    char *defensive = get_defensive(character);
    printf("Your current defensive spell : %s\n", defensive);
    printf("\n");

    printf("\x1b[33m");
    printf("Your current gold balance is: %d gold coins\n", character->gold);
    printf("\x1b[0m\n");

    printf("\x1b[31m");
    printf("Each defensive spell costs 30 gold coins\n\n");
    printf("\x1b[0m");

    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, can_use[i]->spell_name);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= 3) {
        if(character->gold >= 30) {

            if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
                // printf("test ok");
                character->gold = character->gold - 30;
                // printf("%s", can_use[choice - 1]->spell_name);
                set_defensive(character, can_use[choice - 1]);
            } else {
                if (strcmp(can_use[choice - 1]->spell_name, character->defensive_spell->spell_name) == 0) {
                    // printf("test ok");
                    system("clear");
                    printf("%s already has the defensive spell %s\n", character->username,can_use[choice - 1]->spell_name);
                } else {
                    // printf("test ok");
                    character->gold = character->gold - 20;
                    //printf("%s", can_use[choice - 1]->spell_name);
                    set_defensive(character, can_use[choice - 1]);
                }
            }

        }else{
            printf("Insufficient gold coins to make the purchase !\n");
        }
    } else if (choice != 0) {
        printf("Invalid choice: %d\n", choice);
    }

    free(dragon_skin->spell_name);
    free(dragon_skin);
    free(protected_area->spell_name);
    free(protected_area);
    free(stick_to_me->spell_name);
    free(stick_to_me);
}

char *get_heal(Character *character) {

    if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
        return "No heal spell";
    } else {
        return character->heal_spell->spell_name;
    }

}

void set_heal(Character *character, Spell *selection) {

    if (character->heal_spell != NULL) {
        free(character->heal_spell->spell_name);
        free(character->heal_spell);
    }

    character->heal_spell = (Spell*)malloc(sizeof(Spell));
    character->heal_spell->spell_name = strdup(selection->spell_name);
    character->heal_spell->cost = selection->cost;
    character->heal_spell->physical_damage = selection->physical_damage;
    character->heal_spell->magical_damage = selection->magical_damage;

    printf("%s changed the heal spell to %s\n", character->username, get_heal(character));
}

void select_heal_spell(Character *character) {
    system("clear");

    Spell *healing_aura = create_spell("Healing Aura", 83, 0, 150);
    Spell *healing_light_house = create_spell("Healing Light House", 130, 0, 300);
    Spell *heart_of_dragon = create_spell("Heart Of Dragon", 210, 0, 500);

    Spell *can_use[3];
    can_use[0] = healing_aura;
    can_use[1] = healing_light_house;
    can_use[2] = heart_of_dragon;

    char *heal = get_heal(character);
    printf("Your current heal spell : %s\n", heal);
    printf("\n");

    printf("\x1b[33m");
    printf("Your current gold balance is: %d gold coins\n", character->gold);
    printf("\x1b[0m\n");

    printf("\x1b[31m");
    printf("Each heal spell costs 40 gold coins\n\n");
    printf("\x1b[0m");

    for (int i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, can_use[i]->spell_name);
    }

    printf("\n");

    int choice;

    printf("Enter your choice (or 0 to cancel): ");
    scanf("%d", &choice);

    system("clear");

    if (choice >= 1 && choice <= 3) {
        if(character->gold >= 40) {
            if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
                // printf("test ok");
                character->gold = character->gold - 30;
                // printf("%s", can_use[choice - 1]->spell_name);
                set_heal(character, can_use[choice - 1]);
            } else {
                if (strcmp(can_use[choice - 1]->spell_name, character->heal_spell->spell_name) == 0) {
                    // printf("test ok");
                    system("clear");
                    printf("%s already has the heal spell %s\n", character->username,can_use[choice - 1]->spell_name);
                } else {
                    // printf("test ok");
                    character->gold = character->gold - 20;
                    //printf("%s", can_use[choice - 1]->spell_name);
                    set_heal(character, can_use[choice - 1]);
                }
            }
        }else{
            printf("Insufficient gold coins to make the purchase !\n");
        }
    } else if (choice != 0) {
        printf("Invalid choice: %d\n", choice);
    }

    free(healing_aura->spell_name);
    free(healing_aura);
    free(healing_light_house->spell_name);
    free(healing_light_house);
    free(heart_of_dragon->spell_name);
    free(heart_of_dragon);
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

