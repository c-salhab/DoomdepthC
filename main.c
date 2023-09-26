#include <stdio.h>
#include <stdlib.h>

#include "Game.c"

int main() {
    Player * player = new_player("Andre");
    weapon_starter_selection(player);
    Battle * battle = init_simple_battle(player);
    wave_battle(battle);
}
