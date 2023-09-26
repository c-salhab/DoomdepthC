#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Monster
{
    char * name;

    int pv_max;
    int att_max;
    int def_max;

    int pv;

    int exp_reward;

}Monster;


Monster * init_monster(char*name,int pv_max,int att_max,int def_max,
                        int pv,
                        int exp_reward)
{
    Monster * monster = malloc(sizeof(Monster));
    monster ->name = name;
    monster -> pv_max = pv_max;
    monster -> att_max = att_max;
    monster -> def_max = def_max;
    monster -> pv = pv;
    monster -> exp_reward = exp_reward;
}

Monster ** dumb_monster_list()
{
    Monster ** list_monster = malloc(sizeof(Monster*)*6);
    for(int i=0;i<6;i++)
    {
        list_monster[i]=malloc(sizeof(Monster));
    }
    list_monster[0]=init_monster("Goblin",10,3,1,10,10);
    list_monster[1]=init_monster("Pikachu",10,3,1,10,10);
    list_monster[2]=init_monster("Yorick",10,3,1,10,10);
    list_monster[3]=init_monster("Giant spider",10,3,1,10,10);
    list_monster[4]=init_monster("Bat",10,3,1,10,10);
    list_monster[5]=init_monster("Snake",10,3,1,10,10);

    return list_monster;
}

Monster ** wave_generation(int wave_size,Monster ** list_monster,int list_monster_size)
{
    
    Monster ** monster_wave = malloc(sizeof(Monster*)*wave_size);
    srand(time(NULL));

    for(int i=0;i<wave_size;i++)
    {
        
        monster_wave[i]=malloc(sizeof(Monster));

        int r = rand()%list_monster_size;
        Monster * monster = (list_monster)[r];
        Monster * monster_i = init_monster(monster->name,monster->pv_max,monster->att_max
                                ,monster->def_max,monster->pv,monster->exp_reward);
        monster_wave[i]=monster_i;
        
    }
    return monster_wave;
}

int monster_is_alive(Monster*monster)
{
    return monster->pv>=0;
}

int wave_is_alive(Monster**wave,int wave_size)
{
    for(int i=0;i<wave_size;i++)
    {
        if(wave[i]->pv>0)
        {
            return 1;
        }
    }
    printf("\nWave finished!\n");
    return 0;
}

void print_wave(Monster**monsters,int size)
{
    printf("\n");
    for(int i=0;i<size;i++)
    {
        if(monster_is_alive(monsters[i]))
        {
            printf("%d - %s | %d/%d PV \n",i+1,monsters[i]->name,monsters[i]->pv,monsters[i]->pv_max);
        }  
    }
    printf("\n");
}