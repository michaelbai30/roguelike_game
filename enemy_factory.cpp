// NOTE: THIS IS NOT YET USED
#include "enemy_factory.h"
#include "stats.h"
#include <cstdlib>

Character generateEnemy(int factor){
    int base = 5 + factor * 2; // basic enemy scaling formula. replace later.

    Stats enemyStats;
    int hp = 20 + factor * 5;
    enemyStats.attack = base;
    enemyStats.armor = base / 2;
    enemyStats.magicDmg = base;
    enemyStats.magicResist = base / 2;
    enemyStats.speed = 5 + base;
    enemyStats.critChance = 10 + (rand() % 10);
    enemyStats.charisma = 0;
    return Character("Goblin", hp, enemyStats); // replace with variety later
}