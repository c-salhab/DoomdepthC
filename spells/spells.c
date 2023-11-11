/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/character.h"
#include "../headers/spells.h"
// Spell *create_spell(int id, char *spell_name, int cost, int offensive, int defensive, int heal, int, int action_point_cost, int level)
// {
//     // allocate memory for a new spell struct
//     Spell *new_spell = malloc(sizeof(Spell));

//     // assign values to the fields of the new spell
//     new_spell->id = id;
//     new_spell->spell_name = strdup(spell_name);
//     new_spell->cost = cost;
//     new_spell->offensive = offensive;
//     new_spell->defensive = defensive;
//     new_spell->heal = heal;
//     new_spell->action_point_cost = action_point_cost;
//     new_spell->level = level;

//     // return the newly created spell
//     return new_spell;
// }

Spell *create_offensive_spell(int id,char *spell_name, int cost, int damage, int action_point_cost, int level)
{
    // allocate memory for a new spell struct
    Spell *new_spell = malloc(sizeof(Spell));

    // assign values to the fields of the new spell
    new_spell->id = id;
    new_spell->spell_name = strdup(spell_name);
    new_spell->cost = cost;
    new_spell->damage = damage;
    new_spell->action_point_cost = action_point_cost;
    new_spell->level = level;

    // return the newly created spell
    return new_spell;
}

Spell*spell_from_csv(char*filename, int index) 
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; char spell_name[50]; int cost; int quantity; int action_point_cost; int level;

            if (sscanf(line, "%d,%49[^,],%d,%d,%d,%d", &id, spell_name, &cost, &quantity, &action_point_cost, &level) == 6) 
            {
                fclose(file);
                return create_offensive_spell(id,spell_name, cost, quantity, action_point_cost, level);
            } else {
                fclose(file);
                perror("Error parsing CSV line");
                exit(EXIT_FAILURE);
            }
        }

        current_index+=1;
    }

    fclose(file);
}


// char *get_offensive(Character *character) {
//     // check if the character has an offensive spell assigned
//     if (character->offensive_spell == NULL) {
//         return "No offensive spell";
//     } else {
//         // return the name of the offensive spell associated with the character
//         return character->offensive_spell->spell_name;
//     }

// }

// void set_offensive(Character *character, Spell *selection) {
//     // check if the character already has an offensive spell
//     if (character->offensive_spell != NULL) {
//         // free the memory occupied by the previous offensive spell's name and the spell itself
//         free(character->offensive_spell->spell_name);
//         free(character->offensive_spell);
//     }

//     // allocate memory for the character's new offensive spell and assign the values from the selected spell
//     character->offensive_spell = (Spell*)malloc(sizeof(Spell));
//     character->offensive_spell->spell_name = strdup(selection->spell_name);
//     character->offensive_spell->cost = selection->cost;
//     character->offensive_spell->offensive = selection->offensive;
//     character->offensive_spell->defensive = selection->defensive;
//     character->offensive_spell->heal = selection->heal;

//     printf("%s changed the offensive spell to %s\n", character->username, character->offensive_spell->spell_name);
// }

// void select_offensive_spell(Character *character) {
//     system("clear");

//     // create different spells

//     Spell *dragon_breath = create_spell("Dragon Breath", 100, 500, 0,0,0);
//     Spell *eat_this = create_spell("Eat This", 65, 300, 0, 0,0);
//     Spell *lightning_chain = create_spell("Lightning Chain", 65, 300, 0,0,0);

//     // store the spells in an array
//     Spell *can_use[3];
//     can_use[0] = dragon_breath;
//     can_use[1] = eat_this;
//     can_use[2] = lightning_chain;

//     // get the current offensive spell of the character
//     char *offensive = get_offensive(character);
//     printf("Your current offensive spell : %s\n", offensive);
//     printf("\n");

//     printf("\x1b[33m");
//     printf("Your current gold balance is: %d gold coins\n", character->gold);
//     printf("\x1b[0m\n");

//     printf("\x1b[31m");
//     printf("Each offensive spell costs 20 gold coins\n\n");
//     printf("\x1b[0m");

//     // display the available spells for selection
//     for (int i = 0; i < 3; i++) {
//         printf("%d. %s\n", i + 1, can_use[i]->spell_name);
//     }

//     printf("\n");

//     int choice;

//     printf("Enter your choice (or 0 to cancel): ");
//     scanf("%d", &choice);

//     system("clear");

//     if (choice >= 1 && choice <= 3) {
//         // check if the character has enough gold to purchase the spell
//         if(character->gold >= 20){

//             if (character->offensive_spell == NULL || character->offensive_spell->spell_name == NULL) {
//                 // set the new offensive spell for the character
//                 // printf("test ok");
//                 character->gold = character->gold - 20;
//                 // printf("%s", can_use[choice - 1]->spell_name);
//                 set_offensive(character, can_use[choice - 1]);
//             } else {
//                 // change the offensive spell if it is different from the current one
//                 if (strcmp(can_use[choice - 1]->spell_name, character->offensive_spell->spell_name) == 0) {
//                     // printf("test ok");
//                     system("clear");
//                     printf("%s already has the offensive spell %s\n", character->username,can_use[choice - 1]->spell_name);
//                 } else {
//                     // printf("test ok");
//                     character->gold = character->gold - 20;
//                     //printf("%s", can_use[choice - 1]->spell_name);
//                     set_offensive(character, can_use[choice - 1]);
//                 }
//             }


//         }else{
//             printf("Insufficient gold coins to make the purchase !\n");
//         }

//     } else if (choice != 0) {
//         printf("Invalid choice : %d\n", choice);
//     }

//     // deallocate memory occupied by the spells
//     free(dragon_breath->spell_name);
//     free(dragon_breath);
//     free(eat_this->spell_name);
//     free(eat_this);
//     free(lightning_chain->spell_name);
//     free(lightning_chain);
// }

// char *get_defensive(Character *character) {
//     // check if the character has a defensive spell assigned
//     if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
//         return "No defensive spell";
//     } else {
//         // return the name of the defensive spell associated with the character
//         return character->defensive_spell->spell_name;
//     }

// }

// void set_defensive(Character *character, Spell *selection) {
//     // check if the character already has a defensive spell
//     if (character->defensive_spell != NULL) {
//         // free the memory occupied by the previous defensive spell's name and the spell itself
//         free(character->defensive_spell->spell_name);
//         free(character->defensive_spell);
//     }

//     // allocate memory for the character's new defensive spell and assign the values from the selected spell
//     character->defensive_spell = (Spell*)malloc(sizeof(Spell));
//     character->defensive_spell->spell_name = strdup(selection->spell_name);
//     character->defensive_spell->cost = selection->cost;
//     character->defensive_spell->offensive = selection->offensive;
//     character->defensive_spell->defensive = selection->defensive;
//     character->defensive_spell->heal = selection->heal;

//     printf("%s changed the defensive spell to %s\n", character->username, get_defensive(character));
// }

// void select_defensive_spell(Character *character) {
//     system("clear");

//     // create different spells
//     Spell *dragon_skin = create_spell("Dragon Skin", 40, 0, 40, 0,0);
//     Spell *protected_area = create_spell("Protected Area", 40, 0,40, 0,0);
//     Spell *stick_to_me = create_spell("Stick To Me", 100, 0,120, 0,0);

//     // store the spells in an array
//     Spell *can_use[3];
//     can_use[0] = dragon_skin;
//     can_use[1] = protected_area;
//     can_use[2] = stick_to_me;

//     // get the current defensive spell of the character
//     char *defensive = get_defensive(character);
//     printf("Your current defensive spell : %s\n", defensive);
//     printf("\n");

//     printf("\x1b[33m");
//     printf("Your current gold balance is: %d gold coins\n", character->gold);
//     printf("\x1b[0m\n");

//     printf("\x1b[31m");
//     printf("Each defensive spell costs 30 gold coins\n\n");
//     printf("\x1b[0m");

//     // display the available spells for selection
//     for (int i = 0; i < 3; i++) {
//         printf("%d. %s\n", i + 1, can_use[i]->spell_name);
//     }

//     printf("\n");

//     int choice;

//     printf("Enter your choice (or 0 to cancel): ");
//     scanf("%d", &choice);

//     system("clear");

//     if (choice >= 1 && choice <= 3) {
//         if(character->gold >= 30) {

//             if (character->defensive_spell == NULL || character->defensive_spell->spell_name == NULL) {
//                 // set the new defensive spell for the character
//                 // printf("test ok");
//                 character->gold = character->gold - 30;
//                 // printf("%s", can_use[choice - 1]->spell_name);
//                 set_defensive(character, can_use[choice - 1]);
//             } else {
//                 // change the defensive spell if it is different from the current one
//                 if (strcmp(can_use[choice - 1]->spell_name, character->defensive_spell->spell_name) == 0) {
//                     // printf("test ok");
//                     system("clear");
//                     printf("%s already has the defensive spell %s\n", character->username,can_use[choice - 1]->spell_name);
//                 } else {
//                     // printf("test ok");
//                     character->gold = character->gold - 20;
//                     //printf("%s", can_use[choice - 1]->spell_name);
//                     set_defensive(character, can_use[choice - 1]);
//                 }
//             }

//         }else{
//             printf("Insufficient gold coins to make the purchase !\n");
//         }
//     } else if (choice != 0) {
//         printf("Invalid choice: %d\n", choice);
//     }

//     // deallocate memory occupied by the spells
//     free(dragon_skin->spell_name);
//     free(dragon_skin);
//     free(protected_area->spell_name);
//     free(protected_area);
//     free(stick_to_me->spell_name);
//     free(stick_to_me);
// }

// char *get_heal(Character *character) {
//     // check if the character has a heal spell assigned
//     if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
//         return "No heal spell";
//     } else {
//         // return the name of the heal spell associated with the character
//         return character->heal_spell->spell_name;
//     }

// }

// void set_heal(Character *character, Spell *selection) {
//     // check if the character already has a heal spell
//     if (character->heal_spell != NULL) {
//         // free the memory occupied by the previous heal spell's name and the spell itself
//         free(character->heal_spell->spell_name);
//         free(character->heal_spell);
//     }
//     // allocate memory for the character's new heal spell and assign the values from the selected spell
//     character->heal_spell = (Spell*)malloc(sizeof(Spell));
//     character->heal_spell->spell_name = strdup(selection->spell_name);
//     character->heal_spell->cost = selection->cost;
//     character->heal_spell->offensive = selection->offensive;
//     character->heal_spell->defensive = selection->defensive;
//     character->heal_spell->heal = selection->heal;

//     printf("%s changed the heal spell to %s\n", character->username, get_heal(character));
// }

// void select_heal_spell(Character *character) {
//     system("clear");

//     // create different spells
//     Spell *healing_aura = create_spell("Healing Aura", 83, 0, 0, 150,0);
//     Spell *healing_light_house = create_spell("Healing Light House", 130, 0, 0, 300,0);
//     Spell *heart_of_dragon = create_spell("Heart Of Dragon", 210, 0, 0, 500,0);

//     // store the spells in an array
//     Spell *can_use[3];
//     can_use[0] = healing_aura;
//     can_use[1] = healing_light_house;
//     can_use[2] = heart_of_dragon;

//     // get the current heal spell of the character
//     char *heal = get_heal(character);
//     printf("Your current heal spell : %s\n", heal);
//     printf("\n");

//     printf("\x1b[33m");
//     printf("Your current gold balance is: %d gold coins\n", character->gold);
//     printf("\x1b[0m\n");

//     printf("\x1b[31m");
//     printf("Each heal spell costs 40 gold coins\n\n");
//     printf("\x1b[0m");

//     // display the available spells for selection
//     for (int i = 0; i < 3; i++) {
//         printf("%d. %s\n", i + 1, can_use[i]->spell_name);
//     }

//     printf("\n");

//     int choice;

//     printf("Enter your choice (or 0 to cancel): ");
//     scanf("%d", &choice);

//     system("clear");

//     if (choice >= 1 && choice <= 3) {
//         if(character->gold >= 40) {
//             if (character->heal_spell == NULL || character->heal_spell->spell_name == NULL) {
//                 // set the new heal spell for the character
//                 // printf("test ok");
//                 character->gold = character->gold - 30;
//                 // printf("%s", can_use[choice - 1]->spell_name);
//                 set_heal(character, can_use[choice - 1]);
//             } else {
//                 if (strcmp(can_use[choice - 1]->spell_name, character->heal_spell->spell_name) == 0) {
//                     // change the heal spell if it is different from the current one
//                     // printf("test ok");
//                     system("clear");
//                     printf("%s already has the heal spell %s\n", character->username,can_use[choice - 1]->spell_name);
//                 } else {
//                     // printf("test ok");
//                     character->gold = character->gold - 20;
//                     //printf("%s", can_use[choice - 1]->spell_name);
//                     set_heal(character, can_use[choice - 1]);
//                 }
//             }
//         }else{
//             printf("Insufficient gold coins to make the purchase !\n");
//         }
//     } else if (choice != 0) {
//         printf("Invalid choice: %d\n", choice);
//     }

//     // deallocate memory occupied by the spells
//     free(healing_aura->spell_name);
//     free(healing_aura);
//     free(healing_light_house->spell_name);
//     free(healing_light_house);
//     free(heart_of_dragon->spell_name);
//     free(heart_of_dragon);
// }

// /*
//  * the choose_another_spell function presents a menu to the user,
//  * allowing them to choose between selecting an offensive spell, a defensive spell,
//  * or a heal spell for the provided character.
//  * the function displays a menu with options the user to input a choice. based on the input,
//  * the function either cancels the selection or calls the corresponding function to select the desired spell type.
//  * if the user enters an invalid choice, the function displays an error message.
//  *
//  * parameter:
//  * character: a pointer to the character for whom the spell selection is being made
//  */
// void choose_another_spell(Character *character){
//     system("clear");

//     printf("\x1b[34m");
//     printf("\nMenu\n");
//     printf("\x1b[0m");

//     printf("1. Choose an Offensive Spell\n");
//     printf("2. Choose a Defensive Spell\n");
//     printf("3. Choose a Heal Spell\n");
//     printf("0. Cancel\n");

//     printf("\n");
//     int choice;

//     printf("Enter your choice: ");
//     scanf("%d", &choice);

//     switch(choice){
//         case 0:
//             system("clear");
//             break;
//         case 1:
//             system("clear");
//             select_offensive_spell(character);
//             break;
//         case 2:
//             system("clear");
//             select_defensive_spell(character);
//             break;
//         case 3:
//             system("clear");
//             select_heal_spell(character);
//             break;
//         default:
//             system("clear");
//             printf("\nChoose between 0 and 4 !\n");
//     }
// }

