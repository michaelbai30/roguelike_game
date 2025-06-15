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

void gameLoop(Player &player) {
    int stage = 1;

    while (player.isAlive() && stage <= 10) {
        Character enemy = generateEnemy();
        int turnNumber = 1;

        std::cout << "\n==============================\n";
        std::cout << "       Stage " << stage << " Begins\n";
        std::cout << "==============================\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));

        while (player.isAlive() && enemy.isAlive()) {
            std::cout << "\n--- Stage " << stage << " | Turn " << turnNumber << " ---\n";
            combatRound(player, enemy, turnNumber);  // Now passes turnNumber by ref
            turnNumber++;
        }

        if (!player.isAlive()) break;

        std::cout << "\n" << enemy.getName() << " has been defeated!\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));

        // player.addGold(20); TODO LATER
        startRewardPhase(player);

        NextPhase decision = chooseNextPhase();
        if (decision == NextPhase::EVENT) {
            runRandomEvent(player);
        } else {
            loadNextBattle(player);
        }

        stage++; // advance to next stage AFTER event/battle
    }

    std::cout << "\n========== Game Over ==========\n";
}


int main() {
    srand(static_cast<unsigned>(time(0)));

    Player player = createPlayer();
    gameLoop(player);

    return 0;
}
