#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * spell_name;
    char * description;
    int cost;

} Spell;

Spell * init_spell(char*name,
                    int type,
                    int mana_cons,
                    int att,
                    float buff, int buff_duration,
                    int coldown)
{
    Spell * spell = malloc(sizeof(Spell));

    spell -> name = name;
    spell -> type = type;
    spell -> mana_cons = mana_cons;
    spell -> att = att;
    spell -> buff = buff; spell -> buff_duration = buff_duration;
    spell -> coldown = coldown;

    return spell;
}