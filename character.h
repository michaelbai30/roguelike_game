// defines character class (player or enemy)
// characters take in name, maxHP, stats

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "stats.h"

class Character {
public:
    Character(const std::string &name, int maxHP, const Stats &stats);

    std::string getName() const;
    int getHP() const;
    int getMaxHP() const;
    void takeDamage(int damage);
    bool isAlive() const;
    Stats &getStats();
    void setDefending(bool val);
    bool isDefending() const;

protected:
    std::string name;
    int maxHP;
    int hp;
    Stats stats;
    bool defending = false;
};

#endif
