#include "battle_manager.h"
#include "combat.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>

Character generateEnemy(int stage) {

    Stats stats;
    std::string name;
    std::vector<Move> moveList; // The enemy's moveset  
    if (stage < 4){
        // BASIC MOBS

        int pick = rand() % 3;
        switch (pick){
            case 0:
                name = "Imp";
                stats = {20, 20, 4, 2, 7, 2, 7, 1, 7}; // 30 total stats
                moveList = {
                    {"Scratch", Move::Type::Physical, 6},
                    {"Fireball", Move::Type::Magic, 6},
                    {"Defend", Move::Type::Defend, 0}
                };
                break;
            
            case 1:
                name = "Bandit";
                stats = {22, 22, 6, 5, 2, 5, 5, 1, 4}; // 28 total stats
                moveList = {
                    {"Slash", Move::Type::Physical, 9, 70}, 
                    {"Throw Knife", Move::Type::Physical, 5}
                };
                break;
            
            case 2:
                name = "Orc";
                stats = {25, 25, 7, 6, 1, 1, 4, 1, 5}; // 25 total stats
                moveList = {
                    {"Clobber", Move::Type::Physical, 10, 65},
                    {"Smash", Move::Type::Physical, 6},
                    {"Defend", Move::Type::Defend, 0}
                };
                break;
        }
    }
    else if (stage < 9){
            // ELITE MOBS

        int pick = rand() % 3;
        switch (pick){
            case 0:
                name = "Minotaur";
                stats = {45, 45, 11, 8, 3, 3, 3, 1, 6}; // 35 total stats 
                moveList = {
                    {"Charge", Move::Type::Physical, 9},
                    {"Gore Axe", Move::Type::Physical, 15, 80},
                    {"Roar", Move::Type::Defend, 0}
                };
                break;

            case 1:
                name = "Lesser Dragon";
                stats = {50, 50, 4, 5, 10, 7, 2, 1, 4}; // 33 total stats 
                moveList = {
                    {"Flame Breath", Move::Type::Magic, 11},
                    {"Claw", Move::Type::Physical, 11},
                    {"Defend", Move::Type::Defend, 0}
                };
                break;

            case 2:
                name = "Forest Beast";
                stats = {40, 40, 9, 5, 1, 2, 10, 1, 9}; // 37 total stats 
                moveList = {
                    {"Pounce", Move::Type::Physical, 12},
                    {"Assassinate", Move::Type::Physical, 25, 45},
                    {"Howl", Move::Type::Defend, 0}
                };
                break;
        }
    }
    else{
        // FINAL BOSS
        name = "Elder Dragon";
        stats = {8, 9, 14, 10, 3, 1, 5};
        moveList = {
            {"Dragon's Wrath", Move::Type::Magic, 18},
            {"Tail Whip", Move::Type::Physical, 18},
            {"Recover", Move::Type::Heal, 12}
        };
    }

    calculateDerivedStats(stats);
    Character enemy(name, stats.maxHP, stats);

    for (const auto& move : moveList) {
        enemy.addMove(move);
    }

    return enemy;
}

void loadNextBattle(Player &player, int stage) {
    std::cout << "\n--- New Battle Begins ---\n";
    Character enemy = generateEnemy(stage);
}
