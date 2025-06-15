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
    int attack = 0; // strength + (luck / 2);
    int armor = 0; // endurance * 1.5
    int magicDmg = 0; // intelligence + (luck / 2);
    int magicResist = 0; // willpower * 1.5
    int critChance = 0; // luck * 3
};

void calculateDerivedStats(Stats &stats);

#endif