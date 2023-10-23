/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../headers/character.h"
#include "../headers/monsters.h"
#include "../weapon/weapon.c"
#include "../armor/armor.c"

Character *init_character(char *name) {

    Character *character = malloc(sizeof(Character));
    character->username = name;

    character->is_alive = 1;
    character->current_health = 100;
    character->current_mana = 100;

    character->level = 1;
    character->exp = 0;

    character->gold = 0;
    character->offensive_spell = NULL;
    character->defensive_spell = NULL;
    character->heal_spell = NULL;

    character->inventory = (Inventory *)malloc(sizeof(Inventory));
    character->inventory->equipped_weapon = NULL;
    character->inventory->equipped_armor = NULL;

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
    printf("Gold : %d\n", character->gold);
    printf("Character's Level : %d\n", character->level);
    printf("Xp [%d/%d] : ", character->exp, exp_needed_to_level_up);

    int current_xp_indication = (character->exp * 30) / exp_needed_to_level_up;

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

    if(character->current_health < 0){
        printf("Life : 00.00\n");
    }else{
        printf("Life : %.2f\n", character->current_health);
    }

    printf("Mana : %.2f\n", character->current_mana);


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

    if (character->offensive_spell == NULL) {
        printf("No offensive spell\n");
    } else {
        printf("%s\n", character->offensive_spell->spell_name);
    }

    printf("Defensive : ");
    if (character->defensive_spell == NULL) {
        printf("No defensive spell\n");
    } else {
        printf("%s\n", character->defensive_spell->spell_name);
    }
    printf("Heal : ");
    if (character->heal_spell == NULL) {
        printf("No heal spell\n");
    } else {
        printf("%s\n", character->heal_spell->spell_name);
    }

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

    printf("Weapon : ");
    if (character->inventory == NULL || character->inventory->equipped_weapon == NULL) {
        printf("No weapon\n");
    } else {
        printf("%s\n", character->inventory->equipped_weapon->weapon_name);
    }
    printf("Armor : ");
    if (character->inventory == NULL || character->inventory->equipped_armor == NULL) {
        printf("No armor\n");
    } else {
        printf("%s\n", character->inventory->equipped_armor->armor_name);
    }
    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");
}

int has_inventory(Character *character) {
    if (character->inventory->equipped_weapon == NULL || character->inventory->equipped_armor == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void set_weapon(Character *character, Weapon *selection) {
    if (character->inventory->equipped_weapon != NULL) {
        free(character->inventory->equipped_weapon->weapon_name);
        free(character->inventory->equipped_weapon->description);
        free(character->inventory->equipped_weapon);
    }

    character->inventory->equipped_weapon = (Weapon *)malloc(sizeof(Weapon));
    character->inventory->equipped_weapon->type = strdup(selection->type);
    character->inventory->equipped_weapon->weapon_name = strdup(selection->weapon_name);
    character->inventory->equipped_weapon->description = strdup(selection->description);
    character->inventory->equipped_weapon->physical_damage = selection->physical_damage;
    character->inventory->equipped_weapon->magical_damage = selection->magical_damage;
    character->inventory->equipped_weapon->durability = selection->durability;
}

void takes_weapon(Character *character, int weapon) {

    Weapon *pan_flute = create_weapon("Wind", "Pan Flute", "A magical flute that enchants the enemy", 20, 10, 100);
    Weapon *wand_of_callipso = create_weapon("Magic", "Wand of Callipso", "A legendary wand used by ancient wizards", 30, 15, 120);
    Weapon *devil_axe = create_weapon("Melee", "Devil Axe", "A cursed axe that deals massive damage", 50, 0, 150);

    Weapon *can_use[3];
    can_use[0] = pan_flute;
    can_use[1] = wand_of_callipso;
    can_use[2] = devil_axe;

    set_weapon(character, can_use[weapon]);

    printf("\n%s takes a %s\n", character->username, character->inventory->equipped_weapon->weapon_name);

}

void set_armor(Character *character, Armor *selection) {
    if (character->inventory->equipped_armor != NULL) {
        free(character->inventory->equipped_armor->armor_name);
        free(character->inventory->equipped_armor);
    }

    character->inventory->equipped_armor = (Armor *)malloc(sizeof(Armor));
    character->inventory->equipped_armor->armor_name = strdup(selection->armor_name);
    character->inventory->equipped_armor->description = selection->description;
    character->inventory->equipped_armor->physical_defense = selection->physical_defense;
    character->inventory->equipped_armor->magical_defense = selection->magical_defense;
    character->inventory->equipped_armor->durability = selection->durability;

}

void takes_armor(Character *character, int armor) {

    Armor *helmet_of_athena = create_armor("Helmet of Athena", "A divine helmet that boosts defense", 50, 20, 100);
    Armor *ares_crown = create_armor("Ares Crown", "A legendary crown worn by powerful warriors", 40, 30, 80);

    Armor *can_wear[2];
    can_wear[0] = helmet_of_athena;
    can_wear[1] = ares_crown;

    set_armor(character, can_wear[armor]);

    printf("\n%s wears a ", character->username);
    if (can_wear[armor] == NULL) {
        printf("nothing to protect himself.\n\n");
    } else {
        printf("%s\n\n", character->inventory->equipped_armor->armor_name);
    }

    free(helmet_of_athena);
    free(ares_crown);
}

void takes_inventory(Character *character) {
    int lucky_luck = rand() % 3;

    if (lucky_luck == 0) {
        takes_weapon(character, rand() % 3);
    } else if (lucky_luck == 1) {
        takes_armor(character, rand() % 2);
    } else {
        printf("\n%s is unlucky, he received nothing to help him in this fight!\n\n", character->username);
    }
}

void character_attack(Character *character, Monster *monster) {

    if (character->offensive_spell != NULL) {
        printf("%s uses the offensive spell : %s\n", character->username, character->offensive_spell->spell_name);
        int damage = character->offensive_spell->offensive;
        monster->life -= damage;
    }else{
        printf("%s doesn't have any offensive spell to use !\n", character->username);
    }

    if (character->heal_spell != NULL) {
        printf("%s uses the heal spell : %s\n", character->username, character->heal_spell->spell_name);
    }else{
        printf("%s doesn't have any heal spell to use !\n", character->username);
    }

    if (character->defensive_spell != NULL) {
        printf("%s uses the defensive spell : %s\n", character->username, character->defensive_spell->spell_name);
    }else{
        printf("%s doesn't have any defensive spell to use !\n", character->username);
    }

    printf("%s attaque le monstre\n", character->username);
    int damage = 10;
    monster->life -= damage;

}


void monster_attack(Character *character, Monster *monster) {
    int damage = rand() % (monster->max_power - monster->min_power + 1) + monster->min_power;
    if (character->defensive_spell != NULL) {
        damage -= character->defensive_spell->cost;
    }
    if (damage > 0) {
        character->current_health -= damage;
    }
}


void fight(Character *character, Monster **list_monsters, int num_monsters) {

    system("clear");

//    int i = 0;
//    srand(time(NULL));
//    character->is_alive = 1;
//
//    int round = 1;
//
//    while (character->is_alive && i < num_monsters) {
//
//        printf("[ROUND : %d]\n", round);
//
//        character_attack(character, list_monsters[i]);
//
//        if (list_monsters[i]->life <= 0) {
//            i++;
//            continue;
//        }
//
//        monster_attack(character, list_monsters[i]);
//
//        if (character->current_health <= 0) {
//            character->is_alive = 0;
//            break;
//        }
//
//        round++;
//    }

    if (character->is_alive) {
        character->gold += rand() % 101;
        if(has_inventory(character)){
            takes_inventory(character);
        }
        printf("%s won the game ! Congratulations ! \n", character->username);
    } else {
        printf("You were defeated by the monsters, try the next time !\n");
    }

}