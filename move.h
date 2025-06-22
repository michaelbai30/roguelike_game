#ifndef MOVE_H
#define MOVE_H

#include <string>

struct Move{
    enum class Type {Physical, Magic, Heal, Defend};
    std::string name;
    Type type;
    int power; // base power of the attack or the heal. 
    float chance = 100; // accuracy

    Move (const std::string &name, Type type, int power, float chance = 1.0) : name(name), type(type), power(power), chance(chance){}
};

#endif