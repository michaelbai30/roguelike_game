#ifndef COMBAT_H
#define COMBAT_H

#include "character.h"
#include "player.h"
#include "move.h"
#include <vector>

void playerTurn(Player &player, Character &enemy);
void enemyTurn(Character &enemy, Player &player);
void showMenu();
void combatRound(Player &player, Character &enemy, int turnNumber);
void animateAction(const std::vector<std::string> &frames, int delayMs);
std::string getHPBar(int current, int max);
int calculateDamage(int atk, int def, bool defending);
int calculateMoveDamage(const Move &move, const Character &user, const Character &target);
bool isCriticalHit(int critChance);
void printStats(const Character &c);
#endif
