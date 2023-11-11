/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/menu.h"
#include "../headers/monsters.h"
#include "../headers/character.h"
#include "../headers/spells.h"
// #include "../headers/map.h"

#include "../map/map.c"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// int get_list_size(Monster **list_monsters) {
//     // initialize size to keep track of the size of the list
//     int size = 0;

//     // continue looping until a null pointer is encountered, which signifies the end of the list
//     while (list_monsters[size] != NULL) {
//         // increment the size for each non null element in the list
//         size++;
//     }

//     // return the total size of the list
//     return size;
// }

void init_game() {

    // initialize the game by clearing the console
    system("clear");

    while (1) {
        // print the title in red
        printf("\x1b[31m");
        printf("  ______ _____  ________  ________ ___________ _____ _   _  _____\n");
        printf(" |  _  \\  _  ||  _  |  \\/  |  _  \\  ___| ___ \\_   _| | | |/  ___|\n");
        printf(" | | | | | | || | | | .  . | | | | |__ | |_/ / | | | |_| |\\ `--.\n");
        printf(" | | | | | | || | | | |\\/| | | | |  __||  __/  | | |  _  | `--. \\\n");
        printf(" | |/ /\\ \\_/ /\\ \\_/ / |  | | |/ /| |___| |     | | | | | |/\\__/ /\n");
        printf(" |___/  \\___/  \\___/\\_|  |_/___/ \\____/\\_|     \\_/ \\_| |_|\\____/\n");
        printf("\x1b[0m");

        // print the menu in blue
        printf("\x1b[34m");
        printf("\nMenu\n");
        printf("\x1b[0m");

        printf("1. Start the game\n");
        printf("0. Exit\n");

        printf("\n");

        int choice;

        // ask the user for input
        printf("\x1b[32m");
        printf("Enter your choice : ");
        printf("\x1b[0m");

        scanf("%d", &choice);

        // switch statement to handle different menu options
        switch (choice) {

            case 1:
                system("clear");
                display_menu();
                break;

            case 0:
                system("clear");
                // exit the program
                printf("Are you sure ? (y)es or (n)o : ");

                char decision;
                scanf(" %c", &decision);

                decision = toupper(decision);

                if (decision == 'Y') {
                    system("clear");
                    printf("\nGoodbye !\n");
                    exit(0);
                } else if (decision == 'N') {
                    system("clear");
                } else {
                    system("clear");
                    printf("You have to choose between yes (Y) or no (N) !\n");
                }
                break;

            default:
                system("clear");
                printf("\nChoose between 0 and 1 !\n");



        }
    }
}

void display_menu() {
    // display the main menu and handle user choices
    // clear console screen
    system("clear");

    // declare a character name array and ask for user input
    char name[100];

    printf("Hello ! What's your name ? ");
    scanf("%s", name);

    system("clear");

    printf("Hello, %s ! Welcome to Doomdepth !\n", name);

    // initialize a character structure using the entered name
    Character *character = init_character(name);
    Weapon*weapon = weapon_from_csv(0);
    set_equipped_weapon(character, weapon);



    // initialize the map
    Map*map=init_new_map();

    // infinite loop for displaying the menu and handling user choices
    while (1) {

        printf("\x1b[34m");
        printf("\nMenu\n");
        printf("\x1b[0m");

        
        printf("1. Map\n");
        printf("2. Inventory\n");
        printf("3. Show Stats\n");

        printf("4. Exit the game\n");
        printf("\n");

        int choice;

        printf("\x1b[32m");
        printf("Enter your choice : ");
        printf("\x1b[0m");

        scanf("%d", &choice);

        // switch statement to handle different menu options
        switch (choice) {            
            case 1:

                system("clear");
                // check map

                map_phase(map,character);
                break;


            case 2:
                system("clear");
                // choose spells
                choose_from_inventory(character);
                break;

            case 3:
                // show the character's statistics
                system("clear");
                show_specs(character);
                break;

            case 4:
                system("clear");
                // exit the program
                printf("Are you sure ? (y)es or (n)o : ");
                char decision;
                scanf(" %c", &decision);

                decision = toupper(decision);

                if (decision == 'Y') {
                    system("clear");
                    printf("\nGoodbye !\n");
                    exit(0);
                } else if (decision == 'N') {
                    system("clear");
                } else {
                    system("clear");
                    printf("You have to choose between yes (Y) or no (N) !\n");
                }
                break;

            default:
                system("clear");
                printf("\nChoose between 0 and 4 !\n");


        }

    }

}