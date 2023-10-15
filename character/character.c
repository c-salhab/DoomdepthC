/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/character.h"
#include "../headers/spells.h"
#include "../headers/monsters.h"
#include "../weapon/weapon.c"
#include "../armor/armor.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Character *init_character(char *name, float max_health, float max_mana) {

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
    character->gold = 0;

    character->offensive_spell = malloc(sizeof(Spell));
    if (character->offensive_spell != NULL) {
        character->offensive_spell->spell_name = NULL;
    } else {
        free(character);
        return NULL;
    }

    character->defensive_spell = malloc(sizeof(Spell));
    if (character->defensive_spell != NULL) {
        character->defensive_spell->spell_name = NULL;
    } else {
        free(character);
        return NULL;
    }

    character->heal_spell = malloc(sizeof(Spell));
    if (character->heal_spell != NULL) {
        character->heal_spell->spell_name = NULL;
    } else {
        free(character);
        return NULL;
    }

    character->gear = NULL;
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
    printf("Gold : %d\n", character->gold);
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

    printf("Offensive : ");

    if (character->offensive_spell == NULL || character->offensive_spell->spell_name == NULL) {
        printf("No offensive spell\n");
    } else {
        printf("%s\n", character->offensive_spell->spell_name);
    }

    printf("Defensive : ");
    if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
        printf("No defensive spell\n");
    } else {
        printf("%s\n", character->defensive_spell->spell_name);
    }
    printf("Heal : ");
    if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
        printf("No heal spell\n");
    } else {
        printf("%s\n", character->heal_spell->spell_name);
    }

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

int has_gear(Character *character) {
    if (character != NULL && character->gear != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void show_gear(Character *character){
    if(character->gear != NULL && (character->gear->equipped_armor != NULL || character->gear->equipped_weapon != NULL)){
        printf("%s has a gear.\n", character->username);
    }else{
        printf("%s's gear is empty.\n", character->username);
    }
}

void takes_weapon(Character *character, int weapon) {

    Weapon *pan_flute = create_weapon("Wind", "Pan Flute", "A magical flute that enchants the enemy", 20, 10, 100);
    Weapon *wand_of_callipso = create_weapon("Magic", "Wand of Callipso", "A legendary wand used by ancient wizards", 30, 15, 120);
    Weapon *devil_axe = create_weapon("Melee", "Devil Axe", "A cursed axe that deals massive damage", 50, 0, 150);

    Weapon *can_use[3];
    can_use[0] = pan_flute;
    can_use[1] = wand_of_callipso;
    can_use[2] = devil_axe;

    character->gear = malloc(sizeof(Gear));
    character->gear->equipped_weapon = can_use[weapon];
    printf("\n%s takes a %s\n", character->username, character->gear->equipped_weapon->weapon_name);

    free(pan_flute);
    free(wand_of_callipso);
    free(devil_axe);
}

void takes_armor(Character *character, int armor) {

    Armor *helmet_of_athena = create_armor("Helmet of Athena", "A divine helmet that boosts defense", 50, 20, 100);
    Armor *ares_crown = create_armor("Ares Crown", "A legendary crown worn by powerful warriors", 40, 30, 80);

    Armor *can_wear[2];
    can_wear[0] = helmet_of_athena;
    can_wear[1] = ares_crown;

    character->gear = malloc(sizeof(Gear));
    character->gear->equipped_armor = can_wear[armor];
    printf("\n%s wears a ", character->username);
    if (can_wear[armor] == NULL) {
        printf("nothing to protect himself.\n\n");
    } else {
        printf("%s\n\n", character->gear->equipped_armor->armor_name);
    }

    free(helmet_of_athena);
    free(ares_crown);
}

void takes_gear(Character *character) {
    int lucky_luck = rand() % 3;

    if (lucky_luck == 0) {
        takes_weapon(character, rand() % 3);
    } else if (lucky_luck == 1) {
        takes_armor(character, rand() % 2);
    } else {
        printf("\n%s is unlucky, he received nothing to help him in this fight!\n\n", character->username);
    }
}

void fight(Character *character, Monster **list_monster){
    system("clear");

    restore(character);

    printf("\n --- {%s} VS {The Monsters} ---\n", character->username);

    int boolean = has_gear(character);

    if(boolean == 1){
        show_gear(character);
    }else{
        takes_gear(character);
    }

    int round = 1;

    while(character->is_alive == 1 && list_monster){

    }
}

