#ifndef POST_REWARD_CHOICE_H
#define POST_REWARD_CHOICE_H

#include "player.h"
#include <vector>

enum NextPhase{
    BATTLE,
    EVENT
};

NextPhase chooseNextPhase();
#endif