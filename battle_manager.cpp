#include "battle_manager.h"
#include "combat.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>

Character generateEnemy() {
    // for now, generate a basic enemy with randomized stats
    std::vector<std::string> names = {"Goblin", "Skeleton", "Orc", "Bandit", "Imp"};

    std::string name = names[rand() % names.size()];
    Stats s;
    int hp = 20 + rand() % 20;
    s.attack = 5 + rand() % 5;
    s.armor = 3 + rand() % 3;
    s.magicDmg = 4 + rand() % 4;
    s.magicResist = 2 + rand() % 3;
    s.speed = 5 + rand() % 5;
    s.critChance = 5 + rand() % 10;
    s.charisma = 0;

    Character enemy(name, hp, s);
    return enemy;
}

void loadNextBattle(Player &player) {
    std::cout << "\n--- New Battle Begins ---\n";
/*
    int numEnemies = 1 + rand() % 3; loads random number of enemies between 1 - 3 
    std::vector<Character> enemies;
    for (int i = 0; i < numEnemies; ++i) {
        enemies.push_back(generateEnemy());
    }

    for (Character& enemy : enemies) {
        std::cout << "Enemy: " << enemy.getName() << " (HP: " << enemy.getHP() << ")\n";
    }

    std::cout << "Prepare for combat...\n";
    std::cin.ignore();
    std::cin.get();

    // TEMP: Fight one-by-one
    for (Character& enemy : enemies) {
        if (!player.isAlive()) break;
        combatRound(player, enemy);
    }
        */

    Character enemy = generateEnemy();
    // combatRound(player, enemy);
}
