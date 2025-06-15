#include "stats.h"

void calculateDerivedStats(Stats& stats) {
    stats.attack       = stats.strength * 2;
    stats.armor        = stats.endurance;
    stats.magicDmg     = stats.intelligence * 2;
    stats.magicResist  = stats.willpower;
    stats.critChance   = stats.luck * 3;
    // stats.speed        = stats.speed;
}
