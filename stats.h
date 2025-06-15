#ifndef STATS_H
#define STATS_H

struct Stats{

    // core stats
    int hp = 0;
    int maxHP = 0;
    int strength = 0;
    int endurance = 0;
    int intelligence = 0;
    int willpower = 0;
    int speed = 0;
    int charisma = 0;
    int luck = 0;

    // derived stats
    // Need to balance this better ... 
    int attack = 0; // strength * 2
    int armor = 0; // endurance * 1
    int magicDmg = 0; // intelligence * 2
    int magicResist = 0; // willpower * 1 
    int critChance = 0; // luck * 3
};

void calculateDerivedStats(Stats &stats);

#endif