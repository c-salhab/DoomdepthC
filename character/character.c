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
    character->current_health = max_health;
    character->current_mana = max_mana;

    character->level = 1;
    character->exp = 0;

    character->gold = 40;
    character->offensive_spell = NULL;
    character->defensive_spell = NULL;
    character->heal_spell = NULL;

    character->inventory = NULL;

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

    printf("Life : %.2f\n", character->current_health);
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

//void restore(Character *character) {
//    character->current_health = character->max_health;
//    character->mana = character->max_mana;
//    character->is_alive = 1;
//}

int has_inventory(Character *character) {
    if (character != NULL && character->inventory != NULL) {
        return 1;
    } else {
        return 0;
    }
}

void show_inventory(Character *character){
    if(character->inventory != NULL && (character->inventory->equipped_armor != NULL || character->inventory->equipped_weapon != NULL)){
        printf("%s has a inventory.\n", character->username);
    }else{
        printf("%s's inventory is empty.\n", character->username);
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

    character->inventory = malloc(sizeof(Inventory));
    character->inventory->equipped_weapon = can_use[weapon];
    printf("\n%s takes a %s\n", character->username, character->inventory->equipped_weapon->weapon_name);

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

    character->inventory = malloc(sizeof(Inventory));
    character->inventory->equipped_armor = can_wear[armor];
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

int all_monsters_alive(Monster **list_monsters, int size) {

    for (int i = 0; i < size; i++) {
        if (list_monsters[i]->life <= 0) {
            return 0;
        }
    }

    return 1;
}

//int potentialDeath(Character *attacker, Monster *target) {
//    return attacker->health > target->life;
//}
//
//void heal(Character *character) {
//    if (character->healSpell) {
//
//        if (character->current_mana >= character->) {
//            if (strcmp(character->healSpell, "fixed") == 0) {
//                character->currentHealth += 50;
//            } else {
//                character->currentHealth *= 1.5;
//            }
//            character->currentMana -= 50;
//            printf("%s a utilisé un sort de guérison\n", character->healSpell);
//            printf("Coût du sort : 50 | Points de mana : %d/%d \n", character->currentMana, character->maxMana);
//            printf("%s Vie Restante : [%d/%d]\n", character->healSpell, character->currentHealth, character->maxHealth);
//        } else {
//            hit(character, target);
//        }
//
//    } else {
//        hit(character, target);
//    }
//}

int fight_algorithm(Character *character, Monster **list_monsters, int size) {

    if (!all_monsters_alive(list_monsters, size)) {
        return -1;
    } else {
        if (character->current_health <= character->current_health * 0.6) {
            return 0;
        } else {
            return 1;
        }
    }
}

void fight(Character *character, Monster **list_monsters){

    system("clear");

    //restore(character);

    printf("\n --- {%s} VS {The Monsters} ---\n", character->username);

    int boolean = has_inventory(character);

    if(boolean == 1){
        show_inventory(character);
    }else{
        takes_inventory(character);
    }

    int round = 1;
    int size = sizeof(list_monsters) / sizeof(list_monsters[0]);

    while(character->is_alive == 1 && all_monsters_alive(list_monsters, size)){

        printf("[ROUND : %d]\n", round);

        if (round % 2) {

            switch (fight_algorithm(character, list_monsters, size)) {
                case 1:
                    printf("hi");
                    //hit(character, list_monsters[0]);
                    break;
                case 0:
                    printf("bye");
                    //heal(character, list_monsters[0]);
                    break;
            }
        } else {
            for (int i = 0; i < size; i++) {
                switch (fight_algorithm(character, list_monsters, 1)) {
                    case 1:
                        //hit(list_monsters, character);
                        break;
                    case 0:
                        //heal(list_monsters, character);
                        break;
                }
            }
        }

        round++;
    }

    printf("\n");

    if(character->is_alive){
        printf("%s won the game ! Congratulations ! \n", character->username);
    }else{
        printf("You were defeated by the monsters, try the next time !\n");
    }

    printf("\n");
}

