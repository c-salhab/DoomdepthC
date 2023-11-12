/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/
#include "../monsters/monsters.c"


typedef struct Battle
{
    Monster**monster_list;
    int monster_list_size;

    Monster**wave;
    int wave_size;


    
    int distance;
}Battle;