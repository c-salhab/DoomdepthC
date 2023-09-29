/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


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

    while (1) {

        printf("\x1b[34m");
        printf("\nMenu\n");
        printf("\x1b[0m");

        printf("0. Show Stats\n");
        printf("1. Fight\n");
        printf("2. Choose spells\n");
        printf("3. Check Characters\n");
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
                // show stats
                break;

            case 1:
                system("clear");
                // attack
                break;

            case 2:
                system("clear");
                // choose spells
                break;

            case 3:
                system("clear");
                // check characters
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