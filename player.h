#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "stats.h"
#include "character.h"
#include <map>

// player is a character
class Player : public Character{
    public:
        Player(const std::string &name, const Stats &stats);

        std::map<std::string, int> &getInventory();
        void heal(int amount);
        void modifyMaxHP(int amount);
        Stats &getStats(); // no const. player stats are modifiable

    private:
        std::map<std::string, int> inventory;
};

Player createPlayer();

#endif