/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include "../headers/menu.h"

void display_menu(){

    char *name;

    printf("Hello ! What's your name ? ");
    scanf("%s", name);

    while(1){

        printf("\nMenu\n");
        printf("0. Show Stats : \n");
        printf("1. Fight !\n");
        printf("2. Choose spells !\n");
        printf("3. Check Characters : \n");
        printf("4. Exit the game\n");

        int choice;

        printf("Enter your choice :  ");
        scanf("%d",&choice);

        switch(choice){

            case 0:
                //
                break;

            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:
                printf("\nGoodbye !\n");
                exit(0);
            default:
                printf("\nChoose between 1 and 4 !\n");

        }

    }
}