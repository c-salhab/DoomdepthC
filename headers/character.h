/*
Created by : Charbel Salhab, Olivier Nart, Bao Nguyen Tran Duc
Date : 27/09/2023
Projet DoomdepthC
*/

typedef struct {

    char * username;
    int is_alive;
    float health;
    float mana;
    float physical_strength;
    float physical_defense;
    int level;
    int exp;
    int exp_needed_to_level_up;
//    Offensive *offensive_spell;
//    Deffensive *defensive_spell;
//    Heal *heal_spell;

} Character;

Character * init_character(char *name);
void show_specs(Character *character);
