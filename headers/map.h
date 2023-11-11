/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

typedef struct Map
{

    int posX;
    int posY;

    int size;
    int**game_map;

    int posX_shop; 
    int posY_shop;

    int posX_last_fight;
    int posY_last_fight;

}Map;

Map *init_map(int posX, int posY, int size, int**game_map, int posX_shop, int posY_shop, int posX_last_fight, int posY_last_fight);
void print_game_map(Map *map);
void print_map(int** map, int size) ;
int**map_generation(int size);
void move(Map *Map,int input);
void diplay_move();
