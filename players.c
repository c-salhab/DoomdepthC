#include <stdio.h>
#include <stdlib.h>

#include "equipment.c"


typedef struct Player
{
    char * name;

    int posX; int posY;

    int level; int exp;

    int pv_max; int mana_max; int att_max; int def_max;

    int pv; int mana; int att; int def; int action_point;

    int monney;

    Weapon *weapon;
    Armor *head; Armor  *left_hand; Armor  *right_hand;

    Weapon **weapons_list;
    Armor **armors_list; 

    int capacity;

}Player;


Player * init_player(char*name,

                    int posX,int posY,

                    int level, int exp,

                    int pv_max, int mana_max, int att_max, int def_max,

                    int pv, int mana, int att, int def, int action_point,

                    int monney,

                    Weapon * weapon,
                    Armor*head,Armor*left_hand,Armor*right_hand,
                    Weapon**weapons_list,
                    Armor**armors_list,

                    int capacity)
{
    Player * player = malloc(sizeof(Player));
    player -> name = name;

    player -> posX = posX; player -> posY = posY;

    player -> level = level; player -> exp = exp;

    player -> pv_max = pv_max;
    player -> mana_max = mana_max;
    player -> att_max = att_max;
    player -> def_max = def_max;

    player -> pv = pv;
    player -> mana = mana;
    player -> att = att;
    player -> def = def;
    player -> action_point = action_point;

    player -> monney=monney;

    player -> weapon = weapon;
    player -> head = head; player -> left_hand = left_hand; player -> right_hand = right_hand;

    player -> capacity = capacity;
}


Player * new_player(char*name)
{
    Player * new_player = init_player(name,
                                    25,0,
                                    1,0,
                                    100,100,0,0,
                                    100,100,0,0,0,
                                    0,
                                    NULL,
                                    NULL,NULL,NULL,
                                    NULL,
                                    NULL,
                                    0);
    return new_player;
}

void player_stat_update(Player * player)
{
    player -> att = player->att_max + player->weapon->att;
    player -> action_point = player->weapon->action_point;
}

void equip_weapon(Player * player, Weapon * weapon)
{
    player -> weapon = weapon;
    player_stat_update(player);
}

void equip_armor(Player * player, Armor * armor)
{
    if(armor -> type == 0)
    {
        player -> head = armor;
    }
    else
    {
        if(player -> left_hand == NULL)
        {
            player -> left_hand = armor;
        }
        else
        {
            player -> right_hand = armor;
        }
    }
    player_stat_update(player);
}