/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/character.h"
#include "../headers/monsters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Character * init_character(char *name, float max_health, float max_mana){
    Character *character = malloc(sizeof(Character));
    character->username = name;
    character->is_alive = 1;
    character->health = max_health;
    character->mana = max_mana;
    character->max_health = max_health;
    character->max_mana = max_mana;
    character->level = 1;
    character->exp = 0;
    character->exp_needed_to_level_up = 50;
    character->physical_strength = 0;
    character->physical_defense = 0;

    return character;
}


void show_specs(Character *character){

    printf("\n");

    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");

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

    printf("Username : %s\n", character->username);
    printf("Character's Level : %d\n", character->level);
    printf("Xp [%d/%d] : ", character->exp, character->exp_needed_to_level_up);

    int current_xp_indication = (character->exp * 30) / character->exp_needed_to_level_up;
    int rest_needed_to_level_up = 30 - current_xp_indication;

    printf("[");
    for(int i = 0; i < current_xp_indication; i++){
        printf("#");
    }
    printf("]\n");

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

    printf("Life : %.2f\n", character->health);
    printf("Mana : %.2f\n", character->mana);
    printf("Physical Force : %.2f\n", character->physical_strength);
    printf("Physical Defense : %.2f\n", character->physical_defense);

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

    printf("Offensive : \n");
    printf("Defensive : \n");
    printf("Heal : \n");

    str = "Gears : ";
    size = strlen(str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }

    printf("%s", str);

    for(int i = 0; i < (60 - size) / 2; i++) {
        printf("-");
    }
    printf("\n");

    printf("Weapon : \n");
    printf("Armor : \n");

    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");
}

void restore(Character *character) {
    character->health = character->max_health;
    character->mana = character->max_mana;
    character->is_alive = 1;
}

int has_gear(){

}

void fight(Character *character, Monster **list_monster){
    system("clear");

    restore(character);

    printf("\n --- {%s} VS {The Monsters} ---\n", character->username);

    int boolean = has_gear(character);

    if(boolean == 1){
        show_gear();
    }else{
        takes_gear();
    }

    int round = 1;

    while(character->is_alive == 1 && list_monster){

    }
}

