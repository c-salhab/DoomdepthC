/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void display_menu() {
    system("clear");

    char name[100];

    printf("Hello! What's your name? ");
    scanf("%s", name);

    system("clear");

    printf("Hello, %s! Welcome to Doomdepth!\n", name);

    while (1) {
        printf("\nMenu\n");
        printf("0. Show Stats\n");
        printf("1. Fight\n");
        printf("2. Choose spells\n");
        printf("3. Check Characters\n");
        printf("4. Exit the game\n");

        int choice;

        printf("Enter your choice: ");
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
                printf("Are you sure? ");
                char decision;
                scanf(" %c", &decision);

                decision = toupper(decision);

                if (decision == 'Y') {
                    printf("\nGoodbye!\n");
                    exit(0);
                } else if (decision == 'N') {
                    system("clear");
                } else {
                    system("clear");
                    printf("You have to choose between yes (Y) or no (N)!\n");
                }
                break;

            default:
                printf("\nChoose between 0 and 4!\n");
        }
    }
}