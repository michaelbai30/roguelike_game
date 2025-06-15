#include "reward_phase.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

void healPlayer(Player &player, int amt) { // heal player for amt health
    int healAmount = std::max(amt, player.getMaxHP() - player.getHP()); 
    player.heal(healAmount);
    std::cout << "You healed for " << healAmount << " HP!\n";
}

void statUp(Player &player) {
    std::cout << "Choose a stat to increase:\n";
    std::cout << "1. Strength\n2. Endurance\n3. Intelligence\n4. Willpower\n5. Speed\n6. Charisma\n7. Luck\n";
    int choice;
    std::cin >> choice;
    Stats &stats = player.getStats(); // must be non const

    switch (choice) {
        case 1: stats.strength++; std::cout << "Strength increased!\n"; break;
        case 2: stats.endurance++; std::cout << "Endurance increased!\n"; break;
        case 3: stats.intelligence++; std::cout << "Intelligence increased!\n"; break;
        case 4: stats.willpower++; std::cout << "Willpower increased!\n"; break;
        case 5: stats.speed++; std::cout << "Speed increased!\n"; break;
        case 6: stats.charisma++; std::cout << "Charisma increased!\n"; break;
        case 7: stats.luck++; std::cout << "Luck increased!\n"; break;
        default: std::cout << "Invalid choice.\n"; break;
    }

    calculateDerivedStats(stats);
}

void giveItem(Player &player) { // TODO: modify to support more items 
    std::cout << "You found a potion!\n";
    player.getInventory()["Potion"]++;
}

//TODO
void visitShop() {
    std::cout << "Shop is under construction!\n";
}
//TODO
void visitCasino() {
    std::cout << "Casino is under construction!\n";
}

// return name of reward given the struct
std::string rewardName(RewardType reward) {
    switch (reward) {
        case RewardType::HEAL: return "Healing Fountain";
        case RewardType::STAT_UP: return "Stat Boost Shrine";
        case RewardType::ITEM: return "Treasure Chest";
        case RewardType::SHOP: return "Merchant";
        case RewardType::CASINO: return "Casino";
        default: return "Unknown";
    }
}

void applyReward(Player &player, RewardType reward) {
    switch (reward) {
        case RewardType::HEAL:
            healPlayer(player, 15);
            break;
        case RewardType::STAT_UP:
            statUp(player);
            break;
        case RewardType::ITEM:
            giveItem(player);
            break;
        case RewardType::SHOP:
            visitShop();
            break;
        case RewardType::CASINO:
            visitCasino();
            break;
    }
}

// picks two out of the five options for the player to choose 
RewardType getRandomRewardFromChoices() {
    std::vector<RewardType> allRewards = {
        RewardType::HEAL,
        RewardType::STAT_UP,
        RewardType::ITEM,
        RewardType::SHOP,
        RewardType::CASINO
    };

    std::shuffle(allRewards.begin(), allRewards.end(), std::default_random_engine(std::random_device{}()));

    RewardType option1 = allRewards[0];
    RewardType option2 = allRewards[1];
    
    // TODO: loop for retries later 
    std::cout << "Choose your reward:\n";
    std::cout << "1. " << rewardName(option1) << "\n";
    std::cout << "2. " << rewardName(option2) << "\n";
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    if (choice == 1) return option1;
    if (choice == 2) return option2;

    // TODO: Change this when we loop for retries later ... 
    std::cout << "Invalid input. Defaulting to first option: " << rewardName(option1) << "\n";
    return option1;
}

void startRewardPhase(Player &player) {
    std::cout << "\n-- Reward Phase --\n";
    RewardType chosenReward = getRandomRewardFromChoices();
    std::cout << "You selected: " << rewardName(chosenReward) << "\n";
    applyReward(player, chosenReward);
}
