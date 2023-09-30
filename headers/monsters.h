/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

typedef struct {
    int life;
    int min_power;
    int max_power;
    int defense;
} Monster;


Monster* init_monster(int life, int min_power, int max_power, int defense);

Monster ** generate_monster();