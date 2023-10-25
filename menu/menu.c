/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/menu.h"
#include "../headers/monsters.h"
#include "../headers/character.h"
#include "../headers/spells.h"
#include "../character/character.c"
#include "../monsters/monsters.c"
#include "../spells/spells.c"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int get_list_size(Monster **list_monsters) {
    int size = 0;
    while (list_monsters[size] != NULL) {
        size++;
    }
    return size;
}

void init_game() {


    system("clear");

    while (1) {

        printf("\x1b[31m");
        printf("  ______ _____  ________  ________ ___________ _____ _   _  _____\n");
        printf(" |  _  \\  _  ||  _  |  \\/  |  _  \\  ___| ___ \\_   _| | | |/  ___|\n");
        printf(" | | | | | | || | | | .  . | | | | |__ | |_/ / | | | |_| |\\ `--.\n");
        printf(" | | | | | | || | | | |\\/| | | | |  __||  __/  | | |  _  | `--. \\\n");
        printf(" | |/ /\\ \\_/ /\\ \\_/ / |  | | |/ /| |___| |     | | | | | |/\\__/ /\n");
        printf(" |___/  \\___/  \\___/\\_|  |_/___/ \\____/\\_|     \\_/ \\_| |_|\\____/\n");
        printf("\x1b[0m");

        printf("\x1b[34m");
        printf("\nMenu\n");
        printf("\x1b[0m");

        printf("1. Start the game\n");
        printf("0. Exit\n");

        printf("\n");

        int choice;

        printf("\x1b[32m");
        printf("Enter your choice : ");
        printf("\x1b[0m");

        scanf("%d", &choice);

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

    system("clear");

    char name[100];

    printf("Hello ! What's your name ? ");
    scanf("%s", name);

    system("clear");

    printf("Hello, %s ! Welcome to Doomdepth !\n", name);

    Character *character = init_character(name);

    while (1) {

        printf("\x1b[34m");
        printf("\nMenu\n");
        printf("\x1b[0m");

        printf("0. Show Stats\n");
        printf("1. Fight\n");
        printf("2. Choose spells\n");
        printf("3. Check Map\n");
        printf("4. Exit the game\n");
        printf("\n");

        int choice;

        printf("\x1b[32m");
        printf("Enter your choice : ");
        printf("\x1b[0m");

        scanf("%d", &choice);

        switch (choice) {

            case 0:
                system("clear");
                show_specs(character);
                break;

            case 1:
                system("clear");
                Monster **monsters = generate_monster();
                int size = get_list_size(monsters);

                scale_monster_stats(monsters, size, character->level);

                if(monsters){
                    // printf("%d", size);
                    fight(character, monsters, size);
                }

                break;

            case 2:
                system("clear");
                // choose spells
                choose_another_spell(character);
                break;

            case 3:
                system("clear");
                // check map
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