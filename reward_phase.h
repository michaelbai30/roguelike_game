#ifndef REWARD_PHASE_H
#define REWARD_PHASE_H

#include "player.h"

enum class RewardType{
    HEAL,
    STAT_UP,
    ITEM,
    SHOP,
    CASINO
};

// types of rewards
void healPlayer(Player &player, int amt);
void statUp(Player &player);
void giveItem(Player &player);
void visitShop();
void visitCasino();

std::string rewardName(RewardType reward);
void applyReward(Player &player, RewardType reward);
RewardType getRandomRewardFromChoices();
void startRewardPhase(Player &player);
#endif