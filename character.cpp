// defines character class (player or enemy)
// characters take in name, maxHP, stats

#include "character.h"
#include "move.h"
#include <cstdlib>
#include <iostream>

Character::Character(const std::string &name, int maxHP, const Stats &stats)
    : name(name), hp(maxHP), maxHP(maxHP), stats(stats), defending(false) {}

std::string Character::getName() const {
    return name;
}

int Character::getHP() const {
    return hp;
}

int Character::getMaxHP() const {
    return maxHP;
}

void Character::takeDamage(int dmg) {
    if (dmg < 0) dmg = 0; // prevent healing through negative damage
    hp -= dmg;
    if (hp < 0) hp = 0;

}

bool Character::isAlive() const {
    return hp > 0;
}

const Stats& Character::getStats() const{
    return stats;
}

void Character::setDefending(bool val){
    defending = val;
}

bool Character::isDefending() const{
    return defending;
}

void Character::addMove(const Move &move){
    moves.push_back(move);
}

const std::vector<Move> &Character::getMove() const {
    return moves;
}

Move Character::chooseMove() const {
    if (moves.empty()) return {"Struggle", Move::Type::Physical, 5}; // fallback
    int idx = rand() % moves.size();
    return moves[idx];
}