#include <stdio.h>
#include <stdlib.h>

typedef struct Weapon
{
    char * name;
    int att;
    int action_point;

    int price;
}Weapon;



typedef struct Armor
{
    char * name;
    int type;
    int def;

    int price;
}Armor;


// Init equipments method

Weapon *init_weapon(char * name,int att,int action_point, int price)
{
    Weapon *weapon = malloc(sizeof(Weapon));
    weapon -> name = name;
    weapon -> att = att;
    weapon -> action_point = action_point;
    weapon ->price = price;
}


Armor *init_armor(char * name,int def, int type, int price)
{
    Armor *armor = malloc(sizeof(armor));
    armor -> name = name;
    armor -> def = def;
    armor -> type = type;
    armor -> price = price;
}