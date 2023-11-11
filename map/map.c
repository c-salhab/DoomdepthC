#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../headers/map.h"
#include "../battle/battle.c"


Map *init_map(int posX, int posY, int size, int**game_map, int posX_shop, int posY_shop, int posX_last_fight, int posY_last_fight)
{
    Map *map=malloc(sizeof(Map));

    map -> posX = posX;
    map -> posY = posY;

    map -> size = size;
    map -> game_map = game_map;

    map -> posX_shop = posX_shop;
    map ->posY_shop = posY_shop;

    map -> posX_last_fight = posX_last_fight;
    map ->posY_last_fight = posY_last_fight;

    return map;
}

Map *init_new_map()
{
    int**game_map=map_generation(20);
    int size = 20;

    int posX_shop = 0;
    int posY_shop = 0;
    
    Map*map = init_map(0,0,size,game_map,posX_shop,posY_shop,0,0);
    // printf("X=%d Y=%d ",map->posX_shop,map->posY_shop);
    return map;
}


void print_game_map(Map *map) 
{   
    printf("\n =  =  =  =  =  =  =  =  =  =  =\n");
    for (int i = 0; i < map->size; i++) 
    {
        for (int j = 0; j < map->size; j++) 
        {
            if(i==map->posX && j==map->posY )
            {           
                printf("\x1b[31m");
                printf(" P ");
                printf("\x1b[0m");
            }

            else if(map->game_map[i][j]<=0)
            {
                printf("   ");
                // printf(" %d ", map->game_map[i][j]);
            }


            else if(map->game_map[i][j]==4)
            {
                printf("\x1b[34m S ");
                printf("\x1b[0m");
            }

            else
            {
                if((i==map->posX - 1 && j==map->posY) || (i==map->posX + 1 && j==map->posY) || (i==map->posX && j==map->posY + 1) || (i==map->posX && j==map->posY - 1))
                {
                    printf("\x1b[33m");
                }
                printf(" %d ", map->game_map[i][j]);
                printf("\x1b[0m");
            }
        }
        printf("\n");
    }
    printf("\n =  =  =  =  =  =  =  =  =  =  =\n");
}


void print_map(int** map, int size) 
{
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int**map_generation(int size)
{
    int**game_map = malloc(sizeof(int*)*size);
    for(int i=0; i<size; i++)
    {
        game_map[i] = malloc(sizeof(int)*size);
    }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) 
            {
                game_map[i][j] = -1;
            }
    }

    return game_map;
}


void update_map(Map * map)
{
    map->game_map[map->posX][map->posY] = abs(map->game_map[map->posX][map->posY]);
}

void move(Map *map,int input)
{
    // UP = 1
    // DOWN = 3
    // RIGHT = 2
    // LEFT = 4

    update_map(map);
    // UP
    if(input=='z' && map->posX > 0 && map->game_map[map->posX-1][map->posY] != 0 && map->game_map[map->posX-1][map->posY] != 4)
    {
        map->posX-=1;
    }

    // DOWN
    if(input=='s' && map->posX < map->size - 1 && map->game_map[map->posX+1][map->posY] != 0&& map->game_map[map->posX+1][map->posY] != 4)
    {
        map->posX+=1;
    }

    // RIGHT
    if(input=='d' && map->posY < map->size - 1 && map->game_map[map->posX][map->posY+1] != 0 && map->game_map[map->posX][map->posY+1] != 4)
    {
        map->posY+=1;
    }

    // LEFT
    if(input=='q' && map->posY > 0 && map->game_map[map->posX][map->posY-1] != 0&& map->game_map[map->posX][map->posY-1] != 4)
    {
        map->posY-=1;
    }
}

void display_move()
{
    printf("            z.UP\n");
    printf("q.LEFT      p.EXIT         d.RIGHT\n");
    printf("            s.DOWN\n");
}


#include <stdio.h>
#include <math.h>

int is_within_radius(int posX, int posY, int X, int Y, int radius) 
{
    int dx = posX - X;
    int dy = posY - Y;
    int distance = sqrt(dx * dx + dy * dy);
    // printf("\ndistance=%d\n",distance);
    if (distance <= radius) {
        return 1;  // Le point est à l'intérieur du rayon
    } else {
        return 0;  // Le point est à l'extérieur du rayon
    }
}


void remove_element(int arr[], int *array_size, int x) {

    for (int i = 0; i < *array_size; i++) {
        if (arr[i] == x) {
            for (int j = i; j < (*array_size - 1); j++) {
                arr[j] = arr[j + 1];
            }
            (*array_size)--;
            i-=1;
        }
    }
}

void forced_battle(Map*map, int X, int Y)
{
    map->game_map[X][Y] = 2;
}

void possilbe_squares(Map*map, int X, int Y, int random, int arr[], int *array_size)
{
    // printf(" random=%d\n",random);
    if(random==4)
    {
        map->posX_shop = X;
        map->posY_shop = Y;
        printf("\nmap[X][Y]=%d",map->posX_shop,map->posY_shop);
        remove_element(arr,array_size,4);
    }
    if(random==0)
    {
        map->posX_shop = X;
        map->posY_shop = Y;
        // printf("\nshopX=%d shopY=posY\n",map->posX_shop,map->posY_shop);
        remove_element(arr,array_size,0);
    }
    // if(map->posX-1>=0)
    // {
    //     if(map->game_map[map->posX-1][map->posY]==0)
    //     {
    //         remove_element(arr,array_size,0);
    //     }  
    // }

    // if(map->posY+1<map->size)
    // {
    //     if(map->game_map[map->posX][map->posY+1]==0)
    //     {
    //         remove_element(arr,array_size,0);
    //     }
    // }

    // if(map->posY-1<map->size && map->game_map[map->posX][map->posY-1]==0)
    // {
    //     remove_element(arr,array_size,0);
    // }
}

int check_obstacle_already_used(int arr[],int array_size)
{
    for(int i=0;i<array_size;i++)
    {
        if(arr[i]==0)
        {
            return 1;
        }
    }
    return 0;
}


void new_squares(Map*map)
{
    srand(time(NULL));
    int arr[] = {0,1,2,3,4};
    int array_size=5;

    if(map->posX==0&&map->posY==0)
    {
        remove_element(arr,&array_size,2);
        remove_element(arr,&array_size,3);
        remove_element(arr,&array_size,4);
    }

    if(is_within_radius(map->posX, map->posY, map->posX_shop, map->posY_shop, 2)==1)
    {
        printf("posX_shop=%d posY_shop=%d\n",map->posX_shop,map->posY_shop);
        remove_element(arr,&array_size,4);
    }


    if(is_within_radius(map->posX, map->posY, map->posX_last_fight, map->posY_last_fight, 1)==1)
    {
        remove_element(arr,&array_size,2);
    }

    int is_forced_battle = is_within_radius(map->posX, map->posY, map->posX_last_fight, map->posY_last_fight, 3) == 0;
    // if(is_forced_battle==1)
    //     {
    //         printf("\n FORCED BATTLE ! \n");
    //     }


    //UP SQUARE
    if(map->posX-1>=0 && map->game_map[map->posX-1][map->posY] < 0)
    {
        if(is_forced_battle==1)
        {
            forced_battle(map,map->posX-1,map->posY);
        }
        else
        {
            int r = rand() % array_size;
            map->game_map[map->posX-1][map->posY] = arr[r];
            // printf("UP SQUARE");
            possilbe_squares(map, map->posX-1, map->posY, r, arr, &array_size);
        }
    }

    //DOwN SQUARE
    if(map->posX+1<map->size && map->game_map[map->posX+1][map->posY] < 0)
    {
        if(is_forced_battle==1)
        {
            forced_battle(map,map->posX+1,map->posY);
        }
        else
        {
            int r = rand() % array_size;
            map->game_map[map->posX+1][map->posY] = arr[r];
            // printf("DOWN SQUARE");
            possilbe_squares(map, map->posX+1, map->posY, r, arr, &array_size);
        }
    }

    //LEFT SQUARE
    if(map->posY-1 >= 0 && map->game_map[map->posX][map->posY-1] < 0)
    {
        if(is_forced_battle==1)
        {
            forced_battle(map,map->posX,map->posY-1);
        }
        else
        {
            int r = rand() % array_size;
            map->game_map[map->posX][map->posY-1] = arr[r];
            // printf("LEFT SQUARE");
            possilbe_squares(map, map->posX, map->posY-1, r, arr, &array_size);
        }
    }

    //RIGHT SQUARE
    if(map->posY+1 < map->size && map->game_map[map->posX][map->posY+1] < 0)
    {
        if(is_forced_battle==1)
        {
            forced_battle(map,map->posX,map->posY+1);
        }
        else
        {
            int r = rand() % array_size;
            map->game_map[map->posX][map->posY+1] = arr[r];
            // printf("RIGHT SQUARE");
            possilbe_squares(map, map->posX, map->posY+1, r, arr, &array_size);
        }

    }

    // printf("\n");
    // for (int i = 0; i < array_size; i++) {
    // printf("%d ", arr[i]);
    // }
}

void battle_trigger(Map*map, Character*player, char*filename)
{
    printf("\nBATTLE BEGIN !!!!\n");
    srand(time(NULL));
    int r = rand()%3;
    int distance=(sqrt((map->posX)*(map->posX)+(map->posY)*(map->posY)))/1.3;
    battle_phase(player, r,distance,filename);
}


void loot(Map*map, Character*player)
{
    srand(time(NULL));
    int distance=(sqrt((map->posX)*(map->posX)+(map->posY)*(map->posY)))/1.3;
    int r = rand()%2;
    if(r==0)
    {   
        int random_gold = (rand()%((distance+1)*10));
        player->gold += random_gold;
        printf("You found %d gold coins !",random_gold);
        Sleep(1500);
    }
    if(r==1)
    {
        int random_id = (rand() % 3) + distance;
        Weapon*random_weapon=weapon_from_csv(random_id);
        printf("You found a %s!\n\n", random_weapon->weapon_name);
        Sleep(700);
        weapon_stat(random_weapon);
        printf("\nDo you want to take it ?\n");
        Sleep(700);
        printf("1. Yes\n2. No\n\n");

        int input;

        scanf("%d",&input);

        if(input==1)
        {
            player->inventory->weapons[player->inventory->num_weapons] = random_weapon;
            player->inventory->num_weapons+=1;
            printf("\nYou obtained %s!",random_weapon->weapon_name);

            printf("\n weapon 0 in inventory: %s\n",player->inventory->weapons[player->inventory->num_weapons-1]->weapon_name);
        }


        Sleep(1500);
    }
}


void map_phase(Map*map, Character*player)
{
    char input = ' ';
    while(input != 'p'&& player_is_alive(player)==1)
    {
        system("cls");
        new_squares(map);
        print_game_map(map);
        display_move();
        scanf("%c",&input);
        move(map,input);
        if(map->game_map[map->posX][map->posY]==2)
        {
            char*filename = "csv_files/bestiary/bestiary.csv";
            battle_trigger(map,player,filename);
            map->posX_last_fight=map->posX;
            map->posY_last_fight=map->posY;
        }
        if(map->game_map[map->posX][map->posY]==3)
        {
            loot(map,player);
        }

        map->game_map[map->posX][map->posY]=1;
    }
}