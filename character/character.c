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

Character *init_character(char *name) {

    Character *character = malloc(sizeof(Character));
    character->username = name;

    character->is_alive = 1;
    character->current_health = max_health;
    character->current_mana = max_mana;

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

    if(character->current_mana < 0){
        printf("Mana : 00.00\n");
    }else{
        printf("Mana : %.2f\n", character->current_mana);
    }

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
    character->inventory->equipped_weapon->durability = selection->durability;
}

void takes_weapon(Character *character, int weapon) {

    Weapon *pan_flute = create_weapon("Wind", "Pan Flute", "A magical flute that enchants the enemy", 20,  5);
    Weapon *wand_of_callipso = create_weapon("Magic", "Wand of Callipso", "A legendary wand used by ancient wizards",  15, 4);
    Weapon *devil_axe = create_weapon("Melee", "Devil Axe", "A cursed axe that deals massive damage", 50, 3);

    Weapon *can_use[3];
    can_use[0] = pan_flute;
    can_use[1] = wand_of_callipso;
    can_use[2] = devil_axe;

    set_weapon(character, can_use[weapon]);

    printf("\n\n%s got a %s\n", character->username, character->inventory->equipped_weapon->weapon_name);

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
    character->inventory->equipped_armor->durability = selection->durability;

}

void takes_armor(Character *character, int armor) {

    Armor *helmet_of_athena = create_armor("Helmet of Athena", "A divine helmet that boosts defense", 50, 3);
    Armor *ares_crown = create_armor("Ares Crown", "A legendary crown worn by powerful warriors", 40, 4);

    Armor *can_wear[2];
    can_wear[0] = helmet_of_athena;
    can_wear[1] = ares_crown;

    set_armor(character, can_wear[armor]);

    printf("\n\n%s got a ", character->username);
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
        printf("\n\n%s is unlucky, he received nothing after winning this fight!\n\n", character->username);
    }
}

void check_inventory(Character *character) {

    for(int k = 0; k <= 50; k++){
        printf("X");
    }

    printf("\n");

    if (character->offensive_spell != NULL) {
        printf("- %s has a %s as an offensive spell.\n", character->username, character->offensive_spell->spell_name);
    }else{
        printf("- %s doesn't have any offensive spell to use !\n", character->username);
    }

    if (character->heal_spell != NULL) {
        printf("- %s has a %s as a heal spell.\n", character->username, character->heal_spell->spell_name);
    }else{
        printf("- %s doesn't have any heal spell to use !\n", character->username);
    }

    if (character->defensive_spell != NULL) {
        printf("- %s has a %s as a defensive spell.\n", character->username, character->defensive_spell->spell_name);
    }else{
        printf("- %s doesn't have any defensive spell to use !\n", character->username);
    }


    if (character->inventory->equipped_weapon != NULL) {
        printf("- %s has a %s as a weapon.\n", character->username, character->inventory->equipped_weapon->weapon_name);
    }else{
        printf("- %s doesn't have any weapon to use !\n", character->username);
    }

    if (character->inventory->equipped_armor != NULL) {
        printf("- %s has a %s as an armor.\n", character->username, character->inventory->equipped_armor->armor_name);
    }else{
        printf("- %s doesn't have any armor to use !\n", character->username);
    }

    for(int a = 0; a <= 50; a++){
        printf("X");
    }

    printf("\n");
}

void character_attack(Character *character, Monster *monster) {
    printf("%s attacks the monsters!\n", character->username);

    int damage = (int)((float)character->current_health * 0.1) + 10;

    if (character->inventory != NULL) {

        if (character->inventory->equipped_weapon != NULL) {
            damage += character->inventory->equipped_weapon->physical_damage;
            printf("%s uses the %s weapon to attack the monsters.\n%s\n", character->username, character->inventory->equipped_weapon->weapon_name, character->inventory->equipped_weapon->description);
            character->inventory->equipped_weapon->durability -= 1;
            if (character->inventory->equipped_weapon->durability <= 0) {
                character->inventory->equipped_weapon = NULL;
                printf("%s's weapon has broken!\n", character->username);
            }
        }

        if (character->inventory->equipped_armor != NULL) {
            character->current_health += character->inventory->equipped_armor->physical_defense;
            printf("%s uses the %s armor to defend against the monsters.\n%s\n", character->username, character->inventory->equipped_armor->armor_name, character->inventory->equipped_armor->description);
            character->inventory->equipped_armor->durability -= 1;
            if (character->inventory->equipped_armor->durability <= 0) {
                character->inventory->equipped_armor = NULL;
                printf("%s's armor has broken!\n", character->username);
            }
        }

    } else {
        printf("%s doesn't have any inventory!\n", character->username);
    }

    if (character->offensive_spell != NULL) {
        damage += character->offensive_spell->offensive;
        printf("%s uses the offensive spell %s.\n", character->username, character->offensive_spell->spell_name);
    }

    if (character->heal_spell != NULL && character->current_mana <= 500) {
        float heal_amount = character->heal_spell->heal;
        character->current_mana += heal_amount;
        printf("%s uses the heal spell %s.\n", character->username, character->heal_spell->spell_name);
    }

    if (character->defensive_spell != NULL) {
        character->current_health += character->defensive_spell->defensive;
        printf("%s uses the defensive spell %s.\n", character->username, character->defensive_spell->spell_name);
    }

    monster->life -= damage;

    for(int j = 0; j < 50; j++){
        printf("-");
    }
}

void monster_attack(Character *character, Monster *monster) {
    int damage = rand() % (monster->max_power - monster->min_power + 1) + monster->min_power;

    character->current_health -= damage;
    character->current_mana -= damage;

    printf("Monster is attacking %s!\n", character->username);
    printf("The monster causes %d damages to %s!\n", damage, character->username);

    for(int j = 0; j < 50; j++){
        printf("-");
    }
}

void has_leveled_up(Character *character){
    character->level += 1;
    character->exp = 0;
    exp_needed_to_level_up *= 1.5;

    character->current_health += character->current_health * 0.5;
    character->current_mana += character->current_mana * 0.5;

    max_health +=   character->current_health * 0.5;
    max_mana += character->current_mana * 0.5;

    printf("\n%s has leveled up !\n", character->username);
    printf("%s is level %d !\n", character->username, character->level);
}

void gain_exp(Character *character){
        float ratio = 0.5;
        
        character->exp += 25 * ratio;
        
        if (character->exp >= exp_needed_to_level_up) {
            has_leveled_up(character);
        }
}

void restore(Character *character){
    character->current_health = max_health;
    character->current_mana = max_mana;
    character->is_alive = 1;
}

void fight(Character *character, Monster **list_monsters, int num_monsters) {

    system("clear");
    check_inventory(character);

    int i = 0;
    restore(character);
    int round = 1;

    printf("\x1b[31m");
    printf("\n%s will fight %d monsters !\n", character->username, num_monsters);
    printf("\x1b[0m");

    while (character->is_alive && i < num_monsters) {

        printf("\n");
        printf("[ROUND : %d]\n", round);

        round++;

        if (round % 2 == 0) {
            character_attack(character, list_monsters[i]);
        } else {
            monster_attack(character, list_monsters[i]);
        }

        if (list_monsters[i]->life <= 0) {
            i++;
            continue;
        }

        if (character->current_health <= 0) {
            character->is_alive = 0;
            break;
        }

    }

    if (character->is_alive) {

        character->gold += 30;

        if(has_inventory(character)){
            takes_inventory(character);
        }

        gain_exp(character);

        printf("\x1b[32m");
        printf("\n\n%s won the game ! Congratulations ! \n", character->username);
        printf("\x1b[0m");
        
    } else {
        printf("\x1b[31m");
        printf("\n\nYou were defeated by the monsters, try the next time !\n");
        printf("\x1b[0m");
    }

}
