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

// declaration and initialization of character variables with null character
char offensive_spell = '\0'; // represents an offensive spell
char defensive_spell = '\0'; // represents a defensive spell
char heal_spell = '\0'; // represents a healing spell

Character *init_character(char *name) {
    // allocate memory for a new character
    Character *character = malloc(sizeof(Character));
    // set the username of the character to the provided name
    character->username = name;

    // set the character as alive
    character->is_alive = 1;
    // set the current health to the maximum health
    character->current_health = max_health;
    // set the current mana to the maximum mana
    character->current_mana = max_mana;

    // set the level to 1
    character->level = 1;
    // set the initial experience points to 0
    character->exp = 0;

    // set the initial gold amount to 0
    character->gold = 0;
    // initialize the offensive spell as null
    character->offensive_spell = NULL;
    // initialize the defensive spell as null
    character->defensive_spell = NULL;
    // initialize the healing spell as null
    character->heal_spell = NULL;

    // allocate memory for the character's inventory
    character->inventory = (Inventory *)malloc(sizeof(Inventory));
    // initialize the equipped weapon and armor in the character's inventory as null
    character->inventory->equipped_weapon = NULL;
    character->inventory->equipped_armor = NULL;

    character->inventory->num_armors = 0;

    character->inventory->num_weapons = 0;

    character->inventory->weapons = malloc(MAX_WEAPONS * sizeof(Weapon*));
    character->inventory->armors = malloc(MAX_ARMORS * sizeof(Armor*));

    for (int i = 0; i < MAX_ARMORS; i++) {
        character->inventory->armors[i] = NULL;
    }

    for (int i = 0; i < MAX_WEAPONS; i++) {
        character->inventory->weapons[i] = NULL;
    }

    // return a pointer to the newly created character
    return character;
}

void set_equipped_armor(Character *character, Armor *selection) {
    // free the memory of the previously equipped armor if it exists
    if (character->inventory->equipped_armor != NULL) {
        free(character->inventory->equipped_armor->armor_name);
        free(character->inventory->equipped_armor);
    }

    // allocate memory for the new equipped armor
    character->inventory->equipped_armor = (Armor *)malloc(sizeof(Armor));

    // copy the attributes of the provided armor to the character's equipped armor
    character->inventory->equipped_armor->armor_name = strdup(selection->armor_name);
    character->inventory->equipped_armor->description = selection->description;
    character->inventory->equipped_armor->physical_defense = selection->physical_defense;
    character->inventory->equipped_armor->durability = selection->durability;
}

void set_equipped_weapon(Character *character, Weapon *selection) {
    // free memory of the previously equipped weapon if it exists
    if (character->inventory->equipped_weapon != NULL) {
        free(character->inventory->equipped_weapon->weapon_name);
        free(character->inventory->equipped_weapon->description);
        free(character->inventory->equipped_weapon);
    }

    // allocate memory for the new equipped weapon
    character->inventory->equipped_weapon = (Weapon *)malloc(sizeof(Weapon));

    // copy the attributes of the selected weapon to the equipped weapon
    character->inventory->equipped_weapon->type = strdup(selection->type);
    character->inventory->equipped_weapon->weapon_name = strdup(selection->weapon_name);
    character->inventory->equipped_weapon->description = strdup(selection->description);
    character->inventory->equipped_weapon->physical_damage = selection->physical_damage;
    character->inventory->equipped_weapon->durability = selection->durability;
}

void choose_from_inventory(Character *character) {

    int choice;
    int max_armor_choice = character->inventory->num_armors;
    int max_weapon_choice = character->inventory->num_weapons;

    printf("\x1b[34m");
    printf("\nEquip from inventory\n");
    printf("\x1b[0m");

    printf("1. Armors\n");
    printf("2. Weapons\n");
    printf("0. Cancel\n");

    printf("\x1b[32m");
    printf("\nEnter your choice : ");
    printf("\x1b[0m");

    scanf("%d", &choice);

    switch (choice) {
        case 0:
            system("clear");
            break;
        case 1:
            system("clear");

            printf("\x1b[34m");
            printf("\nArmors\n");
            printf("\x1b[0m");

            int found = 0;

            for (int i = 0; i < character->inventory->num_armors; i++) {
                if (character->inventory->armors[i] != NULL) {
                    found = 1;
                    printf("%d. %s\n", i + 1, character->inventory->armors[i]->armor_name);
                }
            }

            if (!found) {
                printf("No armors\n");
                break;
            }else{
                printf("0. Cancel\n");
            }

            printf("\x1b[32m");
            printf("\nEnter your choice : ");
            printf("\x1b[0m");

            scanf("%d", &choice);

            if (choice == 0) {
                system("clear");
                break;
            }

            set_equipped_armor(character, character->inventory->armors[choice - 1]);

            break;

        case 2:
            system("clear");

            printf("\x1b[34m");
            printf("\nWeapons\n");
            printf("\x1b[0m");

            int found_weapon = 0;

            for (int i = 0; i < character->inventory->num_weapons; i++) {
                if (character->inventory->weapons[i] != NULL) {
                    found_weapon = 1;
                    printf("%d. %s\n", i + 1, character->inventory->weapons[i]->weapon_name);
                }
            }

            if (!found_weapon) {
                printf("No weapons\n");
                break;
            }else{
                printf("0. Cancel\n");
            }

            printf("\x1b[32m");
            printf("\nEnter your choice : ");
            printf("\x1b[0m");

            scanf("%d", &choice);

            if (choice == 0) {
                system("clear");
                break;
            }

            set_equipped_weapon(character, character->inventory->weapons[choice - 1]);

            break;


        default:
            printf("You have to choose between 0 and 2!\n");
            break;
    }

}

void show_specs(Character *character){

    printf("\n");

    // print a line of 'X' characters for visual separation
    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");

    // print a header with information about the character
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

    // display various details about the character
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

    // print a header for displaying the statistics
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

    // display the current health and mana of the character
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

    // print a header for displaying the character's spells
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

    // display the offensive, defensive, and healing spells of the character
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

    // print a header for displaying the character's inventory
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

    // display the equipped weapon and armor in the character's inventory
    printf("Equipped Weapon : ");
    if (character->inventory == NULL || character->inventory->equipped_weapon == NULL) {
        printf("No equipped weapon\n");
    } else {
        printf("%s\n", character->inventory->equipped_weapon->weapon_name);
    }
    printf("Equipped Armor : ");
    if (character->inventory == NULL || character->inventory->equipped_armor == NULL) {
        printf("No equipped armor\n");
    } else {
        printf("%s\n", character->inventory->equipped_armor->armor_name);
    }

    printf("\n");

    // display armors
    if (character->inventory->num_armors == 0) {
        printf("Armors (Capacity : %d):\nNo armors\n", MAX_ARMORS - 1);
    } else {
        printf("Armors (Capacity : %d):\n", MAX_ARMORS - 1);
        int found_armor = 0;
        for (int i = 0; i < character->inventory->num_armors; i++) {
            if (character->inventory->armors[i] != NULL) {
                found_armor = 1;
                printf("%d. %s\n", i + 1, character->inventory->armors[i]->armor_name);
            }
        }

        if (!found_armor) {
            printf("No armors\n");
        }
    }

    printf("\n");

    // display weapons
    if (character->inventory->num_weapons == 0) {
        printf("Weapons (Capacity : %d):\nNo weapons\n", MAX_WEAPONS - 1);
    } else {
        printf("Weapons (Capacity : %d):\n", MAX_WEAPONS - 1);
        int found_weapon = 0;

        for (int i = 0; i < character->inventory->num_weapons; i++) {
            if (character->inventory->weapons[i] != NULL) {
                found_weapon = 1;
                printf("%d. %s\n", i + 1, character->inventory->weapons[i]->weapon_name);
            }
        }

        if (!found_weapon) {
            printf("No weapons\n");
        }
    }


    // print a line of X characters for visual separation
    for(int i = 0; i < 60; i++){
        printf("X");
    }

    printf("\n");
}

int has_inventory(Character *character) {
    // check if the character's inventory has no equipped weapon or armor
    if (character->inventory->equipped_weapon == NULL || character->inventory->equipped_armor == NULL) {
        return 1; // return 1 if the inventory has no equipped weapon or armor
    } else {
        return 0; // return 0 if the inventory has equipped weapon or armor
    }
}

int has_spells(Character *character) {
    // check if the character has no defensive, offensive, or healing spells
    if (character->defensive_spell == NULL || character->offensive_spell == NULL || character->heal_spell == NULL) {
        return 1; // return 1 if the character has no defensive, offensive, or healing spells
    } else {
        return 0; // return 0 if the character has at least one defensive, offensive, or healing spell
    }
}

void set_weapon(Character *character, Weapon *selection) {
    int i;
    for (i = 0; i < MAX_WEAPONS; i++) {
        if (character->inventory->weapons[i] == NULL) {
            character->inventory->weapons[i] = (Weapon *)malloc(sizeof(Weapon));
            // copy the attributes of the selected weapon to the equipped weapon
            character->inventory->weapons[i]->type = strdup(selection->type);
            character->inventory->weapons[i]->weapon_name = strdup(selection->weapon_name);
            character->inventory->weapons[i]->description = strdup(selection->description);
            character->inventory->weapons[i]->physical_damage = selection->physical_damage;
            character->inventory->weapons[i]->durability = selection->durability;

            character->inventory->num_weapons++;
            break;
        }
    }

    if (i >= MAX_WEAPONS) {
        printf("\n\n%s has received a %s as a reward, but the inventory is full!\n", character->username, selection->weapon_name);
    }

}

void takes_weapon(Character *character, int weapon) {
    // create three different weapons
    Weapon *pan_flute = create_weapon("Wind", "Pan Flute", "A magical flute that enchants the enemy", 20, 5);
    Weapon *wand_of_callipso = create_weapon("Magic", "Wand of Callipso", "A legendary wand used by ancient wizards", 15, 4);
    Weapon *devil_axe = create_weapon("Melee", "Devil Axe", "A cursed axe that deals massive damage", 50, 3);

    // store the created weapons in an array
    Weapon *can_use[3];
    can_use[0] = pan_flute;
    can_use[1] = wand_of_callipso;
    can_use[2] = devil_axe;

    // set the character's equipped weapon based on the selected index from the array
    set_weapon(character, can_use[weapon]);

    printf("\n\n%s got a weapon : %s\n", character->username, can_use[weapon]->weapon_name);

    // free the dynamically allocated memory for each weapon
    free(pan_flute->type);
    free(pan_flute->weapon_name);
    free(pan_flute->description);
    free(pan_flute);

    free(wand_of_callipso->type);
    free(wand_of_callipso->weapon_name);
    free(wand_of_callipso->description);
    free(wand_of_callipso);

    free(devil_axe->type);
    free(devil_axe->weapon_name);
    free(devil_axe->description);
    free(devil_axe);
}

void set_offensive_spells(Character *character, Spell *offensive_spell){
    // free memory of the previously assigned offensive spell if it exists
    if (character->offensive_spell != NULL) {
        free(character->offensive_spell->spell_name);
        free(character->offensive_spell);
    }

    // allocate memory for the new offensive spell
    character->offensive_spell = (Spell*)malloc(sizeof(Spell));

    // copy the attributes of the provided offensive spell to the character's offensive spell
    character->offensive_spell->spell_name = strdup(offensive_spell->spell_name);
    character->offensive_spell->cost = offensive_spell->cost;
    character->offensive_spell->offensive = offensive_spell->offensive;
    character->offensive_spell->defensive = offensive_spell->defensive;
    character->offensive_spell->heal = offensive_spell->heal;
    character->offensive_spell->is_used = offensive_spell->is_used;
}

void takes_offensive_spells(Character *character, int offensive) {
    // create three different spells
    Spell *dragon_breath = create_spell("Dragon Breath", 100, 500, 0, 0, 0);
    Spell *eat_this = create_spell("Eat This", 65, 300, 0, 0, 0);
    Spell *lightning_chain = create_spell("Lightning Chain", 65, 300, 0, 0, 0);

    // store the created spells in an array
    Spell *can_use[3];
    can_use[0] = dragon_breath;
    can_use[1] = eat_this;
    can_use[2] = lightning_chain;

    // set the character's offensive spell based on the selected index from the array
    set_offensive_spells(character, can_use[offensive]);

    printf("\n\n%s got an offensive spell : %s\n", character->username, character->offensive_spell->spell_name);

    free(dragon_breath);
    free(eat_this);
    free(lightning_chain);
}

void set_defensive_spells(Character *character, Spell *selection) {
    // free memory of the previously assigned defensive spell if it exists
    if (character->defensive_spell != NULL) {
        free(character->defensive_spell->spell_name);
        free(character->defensive_spell);
    }

    // allocate memory for the new defensive spell
    character->defensive_spell = (Spell*)malloc(sizeof(Spell));

    // copy the attributes of the provided defensive spell to the character's defensive spell
    character->defensive_spell->spell_name = strdup(selection->spell_name);
    character->defensive_spell->cost = selection->cost;
    character->defensive_spell->offensive = selection->offensive;
    character->defensive_spell->defensive = selection->defensive;
    character->defensive_spell->heal = selection->heal;
    character->defensive_spell->is_used = selection->is_used;
}

void takes_defensive_spells(Character *character, int defensive) {
    // create three different spell instances representing defensive spells
    Spell *dragon_skin = create_spell("Dragon Skin", 40, 0, 40, 0, 0);
    Spell *protected_area = create_spell("Protected Area", 40, 0, 40, 0, 0);
    Spell *stick_to_me = create_spell("Stick To Me", 100, 0, 120, 0, 0);

    // store the created spells in an array
    Spell *can_use[3];
    can_use[0] = dragon_skin;
    can_use[1] = protected_area;
    can_use[2] = stick_to_me;

    // set the character's defensive spell based on the selected index from the array
    set_defensive_spells(character, can_use[defensive]);

    printf("\n\n%s got a defensive spell : %s\n", character->username, character->defensive_spell->spell_name);

    free(dragon_skin);
    free(protected_area);
    free(stick_to_me);
}

void set_heal_spells(Character *character, Spell *selection) {
    // free memory of the previously assigned heal spell if it exists
    if (character->heal_spell != NULL) {
        free(character->heal_spell->spell_name);
        free(character->heal_spell);
    }

    // allocate memory for the new heal spell
    character->heal_spell = (Spell*)malloc(sizeof(Spell));

    // copy the attributes of the provided heal spell to the character's heal spell
    character->heal_spell->spell_name = strdup(selection->spell_name);
    character->heal_spell->cost = selection->cost;
    character->heal_spell->offensive = selection->offensive;
    character->heal_spell->defensive = selection->defensive;
    character->heal_spell->heal = selection->heal;
    character->heal_spell->is_used = selection->is_used;
}

void takes_heal_spells(Character *character, int heal) {

    // create three different spell instances representing heal spells
    Spell *healing_aura = create_spell("Healing Aura", 83, 0, 0, 150, 0);
    Spell *healing_light_house = create_spell("Healing Light House", 130, 0, 0, 300, 0);
    Spell *heart_of_dragon = create_spell("Heart Of Dragon", 210, 0, 0, 500, 0);

    // store the created spells in an array
    Spell *can_use[3];
    can_use[0] = healing_aura;
    can_use[1] = healing_light_house;
    can_use[2] = heart_of_dragon;

    // set the character's heal spell based on the selected index from the array
    set_heal_spells(character, can_use[heal]);

    printf("\n\n%s got a heal spell : %s\n", character->username, character->heal_spell->spell_name);

    free(heart_of_dragon);
    free(healing_light_house);
    free(healing_aura);
}

void set_armor(Character *character, Armor *selection) {
    int i;
    for (i = 0; i < MAX_ARMORS; i++) {
        if (character->inventory->armors[i] == NULL) {
            character->inventory->armors[i] = (Armor *)malloc(sizeof(Armor));
            // copy the attributes of the selected armor to the equipped armor
            character->inventory->armors[i]->armor_name = strdup(selection->armor_name);
            character->inventory->armors[i]->description = strdup(selection->description);
            character->inventory->armors[i]->physical_defense = selection->physical_defense;
            character->inventory->armors[i]->durability = selection->durability;

            character->inventory->num_armors++;
            break;
        }
    }

    if (i >= MAX_ARMORS) {
        printf("\n\n%s has received a %s as a reward, but the inventory is full!\n", character->username, selection->armor_name);
    }
}

void takes_armor(Character *character, int armor) {
    // create two different armors
    Armor *helmet_of_athena = create_armor("Helmet of Athena", "A divine helmet that boosts defense", 50, 3);
    Armor *ares_crown = create_armor("Ares Crown", "A legendary crown worn by powerful warriors", 40, 4);

    // store the created armor instances in an array
    Armor *can_wear[2];
    can_wear[0] = helmet_of_athena;
    can_wear[1] = ares_crown;

    // set the character's armor based on the selected index from the array
    set_armor(character, can_wear[armor]);

    printf("\n\n%s got an armor : %s\n", character->username, can_wear[armor]->armor_name);

    // free the memory allocated for the armors
    free(helmet_of_athena->armor_name);
    free(helmet_of_athena->description);
    free(helmet_of_athena);
    free(ares_crown->armor_name);
    free(ares_crown->description);
    free(ares_crown);
}

void takes_inventory(Character *character) {
    // randomly assign weapons or armors to the character after winning a fight
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
    // randomly assign offensive, defensive, or healing spells to the character after winning a fight
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

    // check and print the availability of offensive, heal, and defensive spells

    if (character != NULL && character->offensive_spell != NULL) {
        if (character->offensive_spell->is_used == 0) {
            printf("- %s has a %s as an offensive spell.\n", character->username, character->offensive_spell->spell_name);
        }
    } else {
        printf("- %s doesn't have any offensive spell to use !\n", character->username);
    }

    if (character != NULL && character->heal_spell != NULL) {
        if (character->heal_spell != NULL && character->heal_spell->is_used == 0) {
            printf("- %s has a %s as a heal spell.\n", character->username, character->heal_spell->spell_name);
        }
    }else{
        printf("- %s doesn't have any heal spell to use !\n", character->username);
    }

    if (character != NULL && character->defensive_spell != NULL) {
        if (character->defensive_spell != NULL && character->defensive_spell->is_used == 0) {
            printf("- %s has a %s as a defensive spell.\n", character->username, character->defensive_spell->spell_name);
        }
    }else{
        printf("- %s doesn't have any defensive spell to use !\n", character->username);
    }

    // check and print the availability of equipped weapon and armor

    if (character->inventory->equipped_weapon != NULL) {
        printf("- %s has a %s as a weapon.\n", character->username, character->inventory->equipped_weapon->weapon_name);
    }else{
        printf("- %s doesn't have any equipped weapon to use !\n", character->username);
    }

    if (character->inventory->equipped_armor != NULL) {
        printf("- %s has a %s as an armor.\n", character->username, character->inventory->equipped_armor->armor_name);
    }else{
        printf("- %s doesn't have any equipped armor to use !\n", character->username);
    }

    for(int a = 0; a <= 50; a++){
        printf("X");
    }

    printf("\n");

    //    if(character->offensive_spell != NULL) {
    //        printf("%d", character->offensive_spell->is_used);
    //    }

    // check if the offensive spell is available and ask the user to use it during the attack
    if(character->offensive_spell != NULL && character->offensive_spell->is_used == 0 && character->current_mana >= character->offensive_spell->cost) {
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

    // check if the heal spell is available and ask the user to use it during the attack
    if(character->heal_spell != NULL && character->heal_spell->is_used == 0 && character->current_mana >= character->heal_spell->cost) {
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

    // check if the defensive spell is available and ask the user to use it during the attack
    if(character->defensive_spell != NULL && character->defensive_spell->is_used == 0 && character->current_mana >= character->defensive_spell->cost) {
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

void remove_weapon(Character *character, Weapon *weapon) {
    int i;
    int found = 0;

    for (i = 0; i < character->inventory->num_weapons; i++) {
        if(strcmp(character->inventory->weapons[i]->weapon_name, weapon->weapon_name) == 0 && !found){
            character->inventory->weapons[i] = NULL;
            found = 1;
        }
    }

    if (character->inventory->equipped_weapon == weapon) {
        free(character->inventory->equipped_weapon->weapon_name);
        free(character->inventory->equipped_weapon->description);
        free(character->inventory->equipped_weapon->type);
        free(character->inventory->equipped_weapon);
        character->inventory->equipped_weapon = NULL;
    }
}

void remove_armor(Character *character, Armor *armor) {
    int i;
    int found = 0;

    for (i = 0; i < character->inventory->num_armors; i++) {
        if(strcmp(character->inventory->armors[i]->armor_name, armor->armor_name) == 0 && !found){
            character->inventory->armors[i] = NULL;
            found = 1;
        }
    }

    if (character->inventory->equipped_armor == armor) {
        free(character->inventory->equipped_armor->armor_name);
        free(character->inventory->equipped_armor->description);
        free(character->inventory->equipped_armor);
        character->inventory->equipped_armor = NULL;
    }
}

void character_attack(Character *character, Monster *monster) {
    // display the character's attack message
    printf("%s attacks the monsters!\n", character->username);

    // calculate the initial damage based on the character's current health
    int damage = (int)((float)character->current_health * 0.2) + 10;

    // check if the character has an inventory
    if (character->inventory != NULL) {
        // check if the character has an equipped weapon and apply the weapon's damage
        if (character->inventory->equipped_weapon != NULL) {
            damage += character->inventory->equipped_weapon->physical_damage;
            printf("%s uses the %s weapon to attack the monsters.\n%s\n", character->username, character->inventory->equipped_weapon->weapon_name, character->inventory->equipped_weapon->description);
            // decrease the durability of the weapon
            character->inventory->equipped_weapon->durability -= 1;
            // check if the weapon's durability has reached 0, and if so, remove the weapon
            if (character->inventory->equipped_weapon->durability <= 0) {
                remove_weapon(character, character->inventory->equipped_weapon);
                printf("%s's weapon has broken!\n", character->username);
            }
        }
        // check if the character has an equipped armor and apply the armor's defense
        if (character->inventory->equipped_armor != NULL) {
            character->current_health += character->inventory->equipped_armor->physical_defense;
            printf("%s uses the %s armor to defend against the monsters.\n%s\n", character->username, character->inventory->equipped_armor->armor_name, character->inventory->equipped_armor->description);
            // decrease the durability of the armor
            character->inventory->equipped_armor->durability -= 1;
            // check if the armor's durability has reached 0, and if so, remove the armor
            if (character->inventory->equipped_armor->durability <= 0) {
                remove_armor(character, character->inventory->equipped_armor);
                printf("%s's armor has broken!\n", character->username);
            }
        }
    } else {
        printf("%s doesn't have any inventory!\n", character->username);
    }

    // check if the character has an offensive spell and the user wants to use it
    if (character->offensive_spell != NULL && offensive_spell == 'Y' && character->offensive_spell->is_used != 1) {
        damage += character->offensive_spell->offensive;
        character->current_mana -= character->offensive_spell->cost;
        printf("%s uses the offensive spell %s.\n", character->username, character->offensive_spell->spell_name);
        character->offensive_spell->is_used = 1;
        character->offensive_spell = NULL;
    }


    // check if the character has a heal spell and the user wants to use it
    if (character->heal_spell != NULL && heal_spell == 'Y' && character->heal_spell->is_used != 1) {
        float heal_amount = character->heal_spell->heal;
        character->current_health += heal_amount;
        character->current_mana -= character->heal_spell->cost;
        printf("%s uses the heal spell %s.\n", character->username, character->heal_spell->spell_name);
        character->heal_spell->is_used = 1;
        character->heal_spell = NULL;
    }

    // check if the character has a defensive spell and the user wants to use it
    if (character->defensive_spell != NULL && defensive_spell == 'Y' && character->defensive_spell->is_used != 1) {
        damage += character->defensive_spell->defensive;
        character->current_mana -= character->defensive_spell->cost;
        printf("%s uses the defensive spell %s.\n", character->username, character->defensive_spell->spell_name);
        character->defensive_spell->is_used = 1;
        character->defensive_spell = NULL;
    }

    // reduce the monster's life by the calculated damage
    monster->life -= damage;
    printf("%s causes %d damages to the Monsters!\n", character->username, damage);

    for(int j = 0; j < 50; j++){
        printf("-");
    }
}

void monster_attack(Character *character, Monster *monster) {
    // calculate the monster's damage within the specified range
    int damage = rand() % (monster->max_power - monster->min_power + 1) + monster->min_power;

    // reduce the character's current health by the calculated damage
    character->current_health -= damage;

    // display the monster's attack message
    printf("Monster is attacking %s!\n", character->username);
    printf("The monster causes %d damages to %s!\n", damage, character->username);

    for(int j = 0; j < 50; j++){
        printf("-");
    }
}

void has_leveled_up(Character *character){
    // increase the character's level by 1
    character->level += 1;
    // reset the character's experience to 0
    character->exp = 0;
    // increase the experience needed to level up for the next level
    exp_needed_to_level_up *= 1.5;

    // increase the character's current health and mana by 50%
    character->current_health += character->current_health * 1.5;
    character->current_mana += character->current_mana * 1.5;

    // increase the maximum health and mana by 50%
    max_health += character->current_health;
    max_mana += character->current_mana;
    MAX_WEAPONS += 2;
    MAX_ARMORS += 2;

    printf("\n%s has leveled up !\n", character->username);
    printf("%s is level %d !\n", character->username, character->level);
}

void gain_exp(Character *character){
    // define a ratio for the experience gain
    float ratio = 1.5;

    // increase the character's experience by 25 times the defined ratio
    character->exp += 25 * ratio;

    // check if the character's experience is greater than or equal to the required experience to level up
    if (character->exp >= exp_needed_to_level_up) {
        // call the has_leveled_up function to handle level-up logic
        has_leveled_up(character);
    }
}

void restore(Character *character){
    // restore the character's health and mana to their maximum values
    character->current_health = max_health;
    character->current_mana = max_mana;
    // set the character's status to alive
    character->is_alive = 1;
}

void fight(Character *character, Monster **list_monsters, int num_monsters) {
    // clear the screen and display the character's inventory
    system("clear");
    check_inventory(character);

    // initialize variables for the fight
    int i = 0;
    restore(character);
    int round = 1;

    // print a message indicating the start of the fight
    printf("\x1b[31m");
    printf("\n%s will fight %d monsters !\n", character->username, num_monsters);
    printf("\x1b[0m");

    // loop through each round of the fight
    while (character->is_alive && i < num_monsters) {

        printf("\n");
        printf("[ROUND : %d]\n", round);

        round++;

        // determine whether it is the character's or monster's turn to attack
        if (round % 2 == 0) {
            character_attack(character, list_monsters[i]);
        } else {
            monster_attack(character, list_monsters[i]);
        }

        // check if the monster has been defeated
        if (list_monsters[i]->life <= 0) {
            i++;
            continue;
        }

        // check if the character has been defeated
        if (character->current_health <= 0) {
            character->is_alive = 0;
            break;
        }

    }

    // if the character is still alive after the fight
    if (character->is_alive) {
        // reward the character with gold
        character->gold += 30;

        // randomly decide whether to give the character an inventory item or a spell
        int lucky_luck = rand() % 2;

        if (lucky_luck == 0) {
            // check if the character has inventory space before adding an item
            if (has_inventory(character)) {
                takes_inventory(character);
            }
        } else if (lucky_luck == 1) {
            // check if the character has spell slots available before adding a spell
            if (has_spells(character)) {
                takes_spells(character);
            }
        }

        // increase the character's experience points
        gain_exp(character);

        // print a message indicating that the character has won the game
        printf("\x1b[32m");
        printf("\n\n%s won the game! Congratulations! \n", character->username);
        printf("\x1b[0m");

    } else {
        // print a message indicating that the character has been defeated
        printf("\x1b[31m");
        printf("\n\nYou were defeated by the monsters, try the next time!\n");
        printf("\x1b[0m");
    }
}
