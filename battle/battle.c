#include "../character/character.c"
#include "../monsters/monsters.c"
#include "../spells/spells.c"
#include <unistd.h>

//#include <windows.h>


void character_attack(Character *character, Monster *monster) {
    // display the character's attack message
    printf("\n%s attacks %s!\n", character->username,monster->name);

    // calculate the initial damage based on the character's current health
    // int damage = (int)((float)character->current_health * 0.2) + 10;
    int damage = 0;

    // check if the character has an inventory
    if (character->inventory != NULL) {
        // check if the character has an equipped weapon and apply the weapon's damage
        if (character->inventory->equipped_weapon != NULL) {
            damage += character->inventory->equipped_weapon->physical_damage;
            // printf("%s uses the %s weapon to attack the monsters.\n%s\n", character->username, character->inventory->equipped_weapon->weapon_name, character->inventory->equipped_weapon->description);
            // decrease the durability of the weapon
            character->inventory->equipped_weapon->durability -= 1;
            // check if the weapon's durability has reached 0, and if so, remove the weapon
            // if (character->inventory->equipped_weapon->durability <= 0) {
            //     remove_weapon(character, character->inventory->equipped_weapon);
            //     printf("%s's weapon has broken!\n", character->username);
            // }
        }
    } 
    else 
    {
        printf("%s doesn't have any inventory!\n", character->username);
    }
    // reduce the monster's life by the calculated damage
    monster->life -= damage;
    printf("%s inflicted %d damages to the %s!\n", character->username, damage,monster->name);

    printf("\n");

    for(int j = 0; j < 50; j++){
        printf("-");
    }
    sleep(1);
}

void spell_damage(Spell*spell, Monster *monster)
{
    if(spell->damage>0)
    {
        monster->life -= spell->damage;
        printf("You used %s on %s and inflicted %d damages!\n", spell->spell_name, monster->name, spell->damage);
    }
}


void monster_attack(Character *character, Monster *monster) {
    if(monster_is_alive(monster)==0)
    {
        return;
    }
    // calculate the monster's damage within the specified range
    int damage = rand() % (monster->max_power - monster->min_power + 1) + monster->min_power;

    // reduce the character's current health by the calculated damage
    character->current_health -= damage;

    // display the monster's attack message
    printf("The %s is attacking %s!\n", monster->name, character->username);
    printf("The %s causes %d damages to %s!\n", monster->name, damage, character->username);
    printf("\n");
    // for(int j = 0; j < 50; j++){
    //     printf("-");
    // }
}

Monster**generate_wave_monsters(char *filename, int id_min, int id_max, int size)
{
     Monster**list_monsters = malloc(size * sizeof(Monster*));
     srand(time(NULL));
          for(int i=0; i<size; i++)
     {
        list_monsters[i]=malloc(size*sizeof(Monster));
     }
     for(int i=0; i<size; i++)
     {
        int random_id = rand() % (id_max - id_min + 1) + id_min;
        list_monsters[i] = read_monster_from_csv(filename, random_id);
     }
     return list_monsters;
}

void print_wave_monsters(Monster**wave, int size)
{
    for(int i=0; i<size; i++)
    {
        if(monster_is_alive(wave[i])==1)
            {
                printf("%d. %s -------- %d PV\n",i+1 ,wave[i]->name,wave[i]->life);
            }
    }
    printf("\n");
}

int wave_is_alive(Monster**wave,int wave_size)
{
    for(int i=0;i<wave_size;i++)
    {
        if(wave[i]->life>0)
        {
            return 1;
        }
    }
    return 0;
}


void delete_monster_from_wave(Monster**wave,int wave_size,int index) 
{
    free(wave[index]);
    for (int i = index; i < wave_size - 1; i++) 
    {
        wave[i] = wave[i + 1];
    }
}


void print_player_turn(Character*player)
{
    printf("It's your turn !\n\n");
    printf("1. Attack\n");
    printf("2. Spell\n");
    printf("3. Items\n");
    printf("4. End your turn\n");
    printf("\n");
}

void player_turn(Character *player, Monster**wave, int wave_size, int*effects, int*effects_duration)
{
    int action_points = 10;
    int end_of_turn = 0;

    while(end_of_turn==0&&wave_is_alive(wave,wave_size)==1)
    {
        int input;
        print_wave_monsters(wave,wave_size);
        printf("========================================== \n\n");
        printf("%d PV || %d MANA || %d Action points\n\n",player->current_health, player->current_mana, action_points);
        print_player_turn(player);
        scanf("%d", &input);

        if(input==1)
        {
            input=10;
            while(input != 0 && action_points !=0 && wave_is_alive(wave,wave_size)==1)
            {   system("cls");
                print_wave_monsters(wave,wave_size);
                printf("========================================== \n\n");
                printf("%d PV || %d MANA || %d Action points\n\n",player->current_health, player->current_mana, action_points);
                printf("Select a target! (0 to go back)\n");
                scanf("%d",&input);
                if(input!=0 && input <= wave_size)
                {
                    character_attack(player,wave[input-1]);
                    action_points-=1;
                }
            }
        }

        if(input==2)
        {
            input=10;
            while(input != 0 && action_points !=0 && wave_is_alive(wave,wave_size)==1)
            {
                system("cls");
                print_wave_monsters(wave,wave_size);
                printf("========================================== \n\n");
                printf("%d PV || %d MANA || %d Action points\n\n",player->current_health, player->current_mana, action_points);

                printf("Select a spell! (0 to go back)\n\n");
                for(int i=1; i<=3; i++)
                {
                    Spell*spell = spell_from_csv(player->spells[i-1]);
                    printf("%i. %s\n",i,spell->spell_name);
                }
                printf("\n");
                scanf("%d",&input);

                if(input>0&&input<=3)
                {
                    if(input!=0 && input <= wave_size)
                    {
                        Spell*spell = spell_from_csv(player->spells[input-1]);

                        int n_targets = spell->n_targets;
                        while(n_targets>0)
                        {
                            system("cls");
                            print_wave_monsters(wave,wave_size);
                            printf("========================================== \n\n");
                            printf("%d PV || %d MANA || %d Action points\n\n",player->current_health, player->current_mana, action_points);
                            printf("Select a taget!\n\n");
                            scanf("%d", &input);
                            spell_damage(spell,wave[input-1]);
                            effects[input-1]=spell->effect_id;
                            effects_duration[input-1]=stat_effect(input-1, "duration");

                            for(int i; i< wave_size; i++)
                            {
                                printf("%d ",effects_duration[i]);
                            }
                            printf("\n");

                            action_points-=1;
                            n_targets-=1;
                            sleep(1);
                        }
                        player->current_mana-= spell->cost;
                    }
                }
            }

        }

        if(input==4)
        {
            end_of_turn=1;
        }

        if(input==10)
        {
            for(int i=0;i<wave_size;i++)
            {
                wave[i]->life=0;
            }
        }
        system("clear");


    }
}

void effect_on_monster(int index, Monster*monster)
{
    FILE *file = fopen("csv_files/spells/effects.csv", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    int current_index = 0;

    while (fgets(line, sizeof(line), file)) {
        if (current_index == index) {
            int id; int duration; int damage; int damage_reduction; int defense_reduction; int freeze;
            char name[50];
            char description[50];

            if (sscanf(line, "%d,%49[^,],%49[^,],%d,%d,%d,%d,%d,%d", &id, name, description, &duration, &damage, &damage_reduction, &defense_reduction, &freeze) == 8)
            {
                fclose(file);

                if(damage>0)
                {
                    monster->life-=damage;
                    printf("%s took %d damages from %s!\n\n",monster->name, damage, name);
                }


            } else {
                fclose(file);
                perror("Error parsing CSV line");
                exit(EXIT_FAILURE);
            }
        }

        current_index+=1;
    }

    fclose(file);
}

void monsters_turn(Character*player, Monster**wave, int wave_size, int*effects, int*effects_duration)
{
    for(int i=0;i<wave_size;i++)
    {
        if(monster_is_alive(wave[i]))
        {
            monster_attack(player,wave[i]);

            sleep(1);
            if(effects_duration[i]>0)
            {
                effect_on_monster(effects[i-1],wave[i]);
                // for(int i=0; i<wave_size; i++)
                // {
                //     printf("%d ",effects_duration[i]);
                // }
                // effects_duration[i]-=1;
                // if(effects_duration[i]==0)
                // {
                //     effects[i]=0;
                // }
            }
        }
        sleep(1);
    }
}

int *effects_tab(int wave_size)
{
    int *effects_duration = (int*)malloc(wave_size * sizeof(int)); // Allouer de la mémoire

    for (int i = 0; i < wave_size; i++) {
        effects_duration[i] = 0;
    }
    return effects_duration;
}

void wave_battle(Character*player, int distance, char *filename)
{
    system("clear");

    int wave_size = 3;
    Monster**wave =generate_wave_monsters(filename, distance, distance+3, wave_size);

    int*effects=effects_tab(wave_size);
    int*effects_duration=effects_tab(wave_size);


    int exp_reward = 0;
    for(int i=0; i<wave_size; i++)
    {
        exp_reward += (wave[i]->level) * 10 * ((wave[i]->level)/(player->level));
    }

    while(wave_is_alive(wave,wave_size)==1 && player->current_health>0)
    {
        player_turn(player,wave,wave_size,effects,effects_duration);
        monsters_turn(player,wave,wave_size, effects, effects_duration);
    }
    system("clear");
    printf("Wave finished!\n");
    sleep(1);

    player->exp += exp_reward;
    printf("\nYou earned %d exp!\n",exp_reward);

    reaward_exp_gain(player,exp_reward);

    sleep(1);
}


void battle_phase(Character *player, int number_of_waves, int distance, char *filename)
{
    system("clear");
    printf("Battle phase !\n\n");
    int n=1;
    while (player_is_alive(player) && n <= number_of_waves)
    {
        printf("------------ WAVE %d/%d ------------",n,number_of_waves);
        sleep(1);
        wave_battle(player,distance,filename);
        n+=1;
    }
    printf("Battle Finished !\n");
}