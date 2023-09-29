/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../players/players.c"
#include "../headers/fight.h"
#include "monster.c"

Battle * init_battle(Player * player,
                     Monster**list_monster,int list_monster_size,
                     Monster**monster_wave,int wave_size,
                     int turn_number,
                     int n_wave,int number_of_waves)
{
    Battle * battle = malloc(sizeof(Battle));
    battle -> player = player;
    battle -> list_monster = list_monster; battle->list_monster_size = list_monster_size;
    battle -> monster_wave = monster_wave; battle -> wave_size = wave_size;
    battle -> turn_number = turn_number;
    battle->n_wave = n_wave; battle -> number_of_waves = number_of_waves;
}

Battle * init_simple_battle(Player * player)
{
    Battle * simple_battle = init_battle(player,dumb_monster_list(),6,NULL,3,0,0,3);
    return simple_battle;
}

void player_attack(Player*player,Monster*monster)
{
    if(player-> att > monster->def_max)
    {
        int damage = (player->att)-(monster->def_max);
        monster -> pv -= damage;

        printf("\n%d damage dealt on %s.",damage,monster->name);
    }
    if(monster->pv<=0)
    {
        printf("\n%s was killed.",monster->name);
    }
    player -> action_point--;
    Sleep(1000);
}

void print_battle_wave(Battle * battle)
{
    print_wave(battle-> monster_wave,battle->wave_size);
}



void player_turn(Battle * battle)
{
    int end_of_turn = 0;
    int input;
    while(end_of_turn==0)
    {
        print_battle_wave(battle);
        printf("========================================== \n\n");
        printf("%d/%d PV || %d/%d MANA || %d PA\n\n",battle->player->pv,
               battle->player->pv_max,
               battle->player->mana,
               battle->player->mana_max,
               battle->player->action_point);
        printf("It's your turn ! \n");
        printf("\n1 - Attack\n2 - Spell\n3 - End of turn\n\n");

        scanf("%d",&input);

        if(input==1)
        {
            input=10;
            while(input != 0 && battle ->player -> action_point !=0)
            {   system("cls");
                print_battle_wave(battle);
                printf("========================================== \n\n");
                printf("Select a target! (0 to go back)\n");
                scanf("%d",&input);
                if(input!=0 && input <= battle->wave_size)
                {
                    player_attack(battle->player,(battle-> monster_wave)[input-1]);
                }
            }
        }
        if(input==3)
        {
            end_of_turn=1;
        }
        system("cls");
    }
}

void monsters_turn(Battle*battle)
{
    for(int i=0;i<battle->wave_size;i++)
    {
        if(monster_is_alive(battle->monster_wave[i]))
        {
            int dammage = (battle->monster_wave[i]->att_max)-(battle->player->def);
            battle -> player -> pv -= dammage;
            printf("You took %d dammage from %s.\n",dammage,battle->monster_wave[i]->name);
            Sleep(800);
        }
    }
    Sleep(1000);
}

void wave_battle(Battle*battle)
{
    Monster**wave = wave_generation(battle->wave_size,battle->list_monster,battle->list_monster_size);
    battle -> monster_wave = wave;

    while(wave_is_alive(battle->monster_wave,battle->wave_size))
    {
        player_turn(battle);
        monsters_turn(battle);
        battle->player->action_point = battle->player->weapon->action_point;
    }
}