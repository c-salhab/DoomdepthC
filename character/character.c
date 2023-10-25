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

char offensive_spell = '\0';
char defensive_spell = '\0';
char heal_spell = '\0';

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

    if (character->offensive_spell == NULL || character->offensive_spell->is_used == 1) {
        printf("No offensive spell\n");
    } else {
        printf("%s\n", character->offensive_spell->spell_name);
    }

    printf("Defensive : ");
    if (character->defensive_spell == NULL || character->defensive_spell->is_used == 1) {
        printf("No defensive spell\n");
    } else {
        printf("%s\n", character->defensive_spell->spell_name);
    }
    printf("Heal : ");
    if (character->heal_spell == NULL || character->heal_spell->is_used == 1) {
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

int has_spells(Character *character) {
    if (character->defensive_spell == NULL || character->offensive_spell == NULL || character->heal_spell == NULL) {
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

    printf("\n\n%s got a weapon : %s\n", character->username, character->inventory->equipped_weapon->weapon_name);

}

void set_offensive_spells(Character *character, Spell *offensive_spell){
    if (character->offensive_spell != NULL) {
        free(character->offensive_spell->spell_name);
        free(character->offensive_spell);
    }

    character->offensive_spell = (Spell*)malloc(sizeof(Spell));
    character->offensive_spell->spell_name = strdup(offensive_spell->spell_name);
    character->offensive_spell->cost = offensive_spell->cost;
    character->offensive_spell->offensive = offensive_spell->offensive;
    character->offensive_spell->defensive = offensive_spell->defensive;
    character->offensive_spell->heal = offensive_spell->heal;
    character->offensive_spell->is_used = offensive_spell->is_used;
}

void takes_offensive_spells(Character *character, int offensive) {

    Spell *dragon_breath = create_spell("Dragon Breath", 100, 500, 0,0,0);
    Spell *eat_this = create_spell("Eat This", 65, 300, 0, 0,0);
    Spell *lightning_chain = create_spell("Lightning Chain", 65, 300, 0,0,0);

    Spell *can_use[3];
    can_use[0] = dragon_breath;
    can_use[1] = eat_this;
    can_use[2] = lightning_chain;

    set_offensive_spells(character, can_use[offensive]);

    printf("\n\n%s got an offensive spell : %s\n", character->username, character->offensive_spell->spell_name);

}

void set_defensive_spells(Character *character, Spell *selection) {

    if (character->defensive_spell != NULL) {
        free(character->defensive_spell->spell_name);
        free(character->defensive_spell);
    }

    character->defensive_spell = (Spell*)malloc(sizeof(Spell));
    character->defensive_spell->spell_name = strdup(selection->spell_name);
    character->defensive_spell->cost = selection->cost;
    character->defensive_spell->offensive = selection->offensive;
    character->defensive_spell->defensive = selection->defensive;
    character->defensive_spell->heal = selection->heal;
    character->defensive_spell->is_used = selection->is_used;

}

void takes_defensive_spells(Character *character, int defensive) {

    Spell *dragon_skin = create_spell("Dragon Skin", 40, 0, 40, 0,0);
    Spell *protected_area = create_spell("Protected Area", 40, 0,40, 0,0);
    Spell *stick_to_me = create_spell("Stick To Me", 100, 0,120, 0,0);

    Spell *can_use[3];
    can_use[0] = dragon_skin;
    can_use[1] = protected_area;
    can_use[2] = stick_to_me;

    set_defensive_spells(character, can_use[defensive]);

    printf("\n\n%s got a defensive spell : %s\n", character->username, character->defensive_spell->spell_name);

}

void set_heal_spells(Character *character, Spell *selection) {

    if (character->heal_spell != NULL) {
        free(character->heal_spell->spell_name);
        free(character->heal_spell);
    }

    character->heal_spell = (Spell*)malloc(sizeof(Spell));
    character->heal_spell->spell_name = strdup(selection->spell_name);
    character->heal_spell->cost = selection->cost;
    character->heal_spell->offensive = selection->offensive;
    character->heal_spell->defensive = selection->defensive;
    character->heal_spell->heal = selection->heal;
    character->heal_spell->is_used = selection->is_used;

}

void takes_heal_spells(Character *character, int heal) {

    Spell *healing_aura = create_spell("Healing Aura", 83, 0, 0, 150,0);
    Spell *healing_light_house = create_spell("Healing Light House", 130, 0, 0, 300,0);
    Spell *heart_of_dragon = create_spell("Heart Of Dragon", 210, 0, 0, 500,0);

    Spell *can_use[3];
    can_use[0] = healing_aura;
    can_use[1] = healing_light_house;
    can_use[2] = heart_of_dragon;

    set_heal_spells(character, can_use[heal]);

    printf("\n\n%s got a heal spell : %s\n", character->username, character->heal_spell->spell_name);

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

    printf("\n\n%s got an armor : %s\n", character->username, character->inventory->equipped_armor->armor_name);

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

void takes_spells(Character *character) {
    int lucky_luck = rand() % 4;

    if (lucky_luck == 0) {
        takes_offensive_spells(character, rand() % 3);
    } else if (lucky_luck == 1) {
        takes_defensive_spells(character, rand() % 3);
    } else if (lucky_luck == 2) {
        takes_heal_spells(character, rand() % 3);
    } else {
        printf("\n\n%s is unlucky, he received nothing after winning this fight!\n\n", character->username);
    }
}

void check_inventory(Character *character) {

    for(int k = 0; k <= 50; k++){
        printf("X");
    }

    printf("\n");

    if (character->offensive_spell != NULL && character->offensive_spell->is_used == 0) {
        printf("- %s has a %s as an offensive spell.\n", character->username, character->offensive_spell->spell_name);
    } else {
        printf("- %s doesn't have any offensive spell to use!\n", character->username);
    }

    if (character->heal_spell != NULL && character->heal_spell->is_used == 0) {
        printf("- %s has a %s as a heal spell.\n", character->username, character->heal_spell->spell_name);
    } else {
        printf("- %s doesn't have any heal spell to use!\n", character->username);
    }

    if (character->defensive_spell != NULL && character->defensive_spell->is_used == 0) {
        printf("- %s has a %s as a defensive spell.\n", character->username, character->defensive_spell->spell_name);
    } else {
        printf("- %s doesn't have any defensive spell to use!\n", character->username);
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

//    if(character->offensive_spell != NULL) {
//        printf("%d", character->offensive_spell->is_used);
//    }

    if(character->offensive_spell != NULL && character->offensive_spell->is_used == 0) {
        do {
            printf("\nDo you want to use the offensive spell %s during the attack? (y)es or (n)o: ",
                   character->offensive_spell->spell_name);
            scanf(" %c", &offensive_spell);
            offensive_spell = toupper(offensive_spell);
            if (offensive_spell != 'Y' && offensive_spell != 'N') {
                printf("\nYou have to choose between yes (Y) or no (N)!\n");
            }
        } while (offensive_spell != 'Y' && offensive_spell != 'N');

        printf("\n");
    }

    if(character->heal_spell != NULL && character->heal_spell->is_used == 0) {
        do {
            printf("\nDo you want to use the heal spell %s during the attack? (y)es or (n)o: ", character->heal_spell->spell_name);
            scanf(" %c", &heal_spell);
            heal_spell = toupper(heal_spell);
            if (heal_spell != 'Y' && heal_spell != 'N') {
                printf("\nYou have to choose between yes (Y) or no (N)!\n");
            }
        } while (heal_spell != 'Y' && heal_spell != 'N');

        printf("\n");
    }

    if(character->defensive_spell != NULL && character->defensive_spell->is_used == 0) {
        do {
            printf("\nDo you want to use the defensive spell %s during the attack? (y)es or (n)o: ",
                   character->defensive_spell->spell_name);
            scanf(" %c", &defensive_spell);
            defensive_spell = toupper(defensive_spell);
            if (defensive_spell != 'Y' && defensive_spell != 'N') {
                printf("\nYou have to choose between yes (Y) or no (N)!\n");
            }
        } while (defensive_spell != 'Y' && defensive_spell != 'N');

        printf("\n");
    }
}

void character_attack(Character *character, Monster *monster) {
    printf("%s attacks the monsters!\n", character->username);

    int damage = (int)((float)character->current_health * 0.5) + 10;

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


    if (character->offensive_spell != NULL && offensive_spell == 'Y') {
            damage += character->offensive_spell->offensive;
            character->current_mana -= character->offensive_spell->cost;
            printf("%s uses the offensive spell %s.\n", character->username, character->offensive_spell->spell_name);
            character->offensive_spell->is_used = 1;
    }

    if (character->heal_spell != NULL && heal_spell == 'Y') {
            float heal_amount = character->heal_spell->heal;
            character->current_health += heal_amount;
            character->current_mana -= character->heal_spell->cost;
            printf("%s uses the heal spell %s.\n", character->username, character->heal_spell->spell_name);
            character->heal_spell->is_used = 1;
    }

    if (character->defensive_spell != NULL && defensive_spell == 'Y') {
            damage += character->defensive_spell->defensive;
            character->current_mana -= character->defensive_spell->cost;
            printf("%s uses the defensive spell %s.\n", character->username, character->defensive_spell->spell_name);
            character->defensive_spell->is_used = 1;
    }

    monster->life -= damage;
    printf("%s causes %d damages to the Monsters!\n",  character->username, damage);

    for(int j = 0; j < 50; j++){
        printf("-");
    }
}

void monster_attack(Character *character, Monster *monster) {
    int damage = rand() % (monster->max_power - monster->min_power + 1) + monster->min_power;

    character->current_health -= damage;

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

        int lucky_luck = rand() % 2;

        if (lucky_luck == 0) {
            if (has_inventory(character)) {
                takes_inventory(character);
            }
        }else if(lucky_luck == 1){
            if(has_spells(character)){
                takes_spells(character);
            }
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
