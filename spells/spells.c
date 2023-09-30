/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include "../headers/character.h"

void select_offensive_spell(Character *character){

}

void choose_another_spell(Character *character){
    system("clear");

    printf("1. Choose an Offensive Spell\n");
    printf("2. Choose a Defense Spell\n");
    printf("3. Choose a Heal Spell\n");

    int choice;

    printf("Enter your choice : ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            select_offensive_spell(character);
            break;
        case 2:
            select_defense_spell(character);
            break;
        case 3:
            select_heal_spell(character);
            break;
        default:
            printf("You have to choose between 1 and 3 !\n");
            break;
    }
}