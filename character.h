// defines character class (player or enemy)
// characters take in name, maxHP, stats

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "stats.h"
#include <vector>
#include "move.h"

class Character {
public:
    Character(const std::string &name, int maxHP, const Stats &stats);

    std::string getName() const;
    int getHP() const;
    int getMaxHP() const;
    void takeDamage(int damage);
    bool isAlive() const;
    const Stats &getStats() const;
    void setDefending(bool val);
    bool isDefending() const;
    void addMove(const Move &move);
    const std::vector<Move> &getMove() const;
    Move chooseMove() const;
private:
    std::vector<Move> moves;

protected:
    std::string name;
    int maxHP;
    int hp;
    Stats stats;
    bool defending = false;
};

#endif
