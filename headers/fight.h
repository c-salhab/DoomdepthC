/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

typedef struct {
    Player * player;
    Monster ** list_monster;

    int list_monster_size;

    Monster ** monster_wave;
    int wave_size;

    int turn_number;

    int n_wave;
    int number_of_waves;

} Battle;

Battle * init_battle(Player * player, Monster**list_monster,int list_monster_size, Monster**monster_wave,int wave_size, int turn_number, int n_wave, int number_of_waves);

Battle * init_simple_battle(Player * player);

void player_attack(Player*player,Monster*monster);

void print_battle_wave(Battle * battle);

void player_turn(Battle * battle);

void monsters_turn(Battle*battle);

void wave_battle(Battle*battle);

