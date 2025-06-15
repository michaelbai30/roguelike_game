#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "player.h"
#include "character.h"
#include <vector>

Character generateEnemy();

void loadNextBattle(Player &player);

#endif
