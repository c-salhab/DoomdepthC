#include <stdio.h>
#include <stdlib.h>

#include "battle_phase.c"

void * weapon_starter_selection(Player*player)
{
    printf("\nSelect your weapon : \n");
    Weapon * sword = init_weapon("Sword",5,4,10);
    equip_weapon(player,sword);
    printf("\nYou are equipped with a %s !\n",player->weapon->name);
}

void New_Game()
{  
    printf("New Game ! \nPlease select a name : ");
    char name[20];
    scanf("%s",name);
    Player * player = new_player(name);
    printf("Your character name is %s !\n",player->name);

    weapon_starter_selection(player);
}