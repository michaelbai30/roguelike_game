#include "stats.h"

void calculateDerivedStats(Stats& stats) {
    stats.attack       = stats.strength + (stats.luck / 2);
    stats.armor        = stats.endurance * 1.5;
    stats.magicDmg     = stats.intelligence + (stats.luck / 2);
    stats.magicResist  = stats.willpower * 1.5;
    stats.critChance   = stats.luck * 3;
    // stats.speed        = stats.speed;
}
