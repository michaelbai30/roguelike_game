#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "character.h"
#include "combat.h"
#include "player.h"
#include "stats.h"
#include "post_reward_choice.h"
#include "reward_phase.h"
#include "event_phase.h"
#include "battle_manager.h"
// #include "enemy_factory.h" // for generateEnemy()

void gameLoop(Player &player) { // round -> reward phase -> choose next phase -> event or next battle 
    while (player.isAlive()) {

        Character enemy = generateEnemy();
        while (player.isAlive() && enemy.isAlive()){
            combatRound(player, enemy); // GENERATES RANDOM. DIFFERENT FROM ENEMY_FACTORY DEFINITION
        }
        if (!player.isAlive()) break;
        std::cout << "\n" << enemy.getName() << " has been defeated!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

       //  player.addGold(20); TODO LATER. Also make a function to regulate gold gen when you beat an enemy. 
        startRewardPhase(player);

        NextPhase decision = chooseNextPhase();
        if (decision == NextPhase::EVENT) {
            runRandomEvent(player);
        } 
        else {
            loadNextBattle(player);
        }
    }

    std::cout << "Game Over!\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    Player player = createPlayer();
    gameLoop(player);

    return 0;
}
