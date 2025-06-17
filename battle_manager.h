#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "player.h"
#include "character.h"
#include <vector>

Character generateEnemy(int stage);

void loadNextBattle(Player &player, int stage);

#endif
