#include "event_phase.h"
#include "player.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <algorithm>

struct Event {
    std::string name;
    std::string description;
    std::function<void(Player&)> effect;
};

// TODO Fill Out Effects 
void runRandomEvent(Player &player) {
    std::vector<Event> events = {
        {
            "Chaos Gate",
            "Suffer -5 HP, gain +5 Attack.",
            [](Player &p) {
             //   p.takeDamage(5);
            //    p.getStats().attack += 5;
            }
        },
        {
            "Deal with the Devil",
            "Lose 10 Max HP, gain +10 Magic Dmg.",
            [](Player &p) {
             //   p.modifyMaxHP(-10);
             //   p.getStats().magicDmg += 10;
            }
        },
        {
            "Healing Spirit",
            "A mysterious force heals you for 15 HP.",
            [](Player &p) {
             //   p.heal(15);
            }
        },
        {
            "Found Gold",
            "You find some stolen gold. Gain 50 coins.",
            [](Player &p) {
            //    p.addGold(50);
            }
        },
        {
            "Thief Encounter",
            "A thief steals 20 coins from you!",
            [](Player &p) {
             //   p.addGold(-20);
            }
        }
    };

    // randomly choose two events
    std::random_shuffle(events.begin(), events.end());
    const Event &option1 = events[0];
    const Event &option2 = events[1];

    // Display choices
    std::cout << "\n--- Random Event Phase ---\n";
    std::cout << "1. " << option1.name << " - " << option1.description << "\n";
    std::cout << "2. " << option2.name << " - " << option2.description << "\n";
    std::cout << "3. Pass\n";
    std::cout << "> ";

    int choice;
    std::cin >> choice;

    switch (choice) {
        case 1:
            std::cout << "You chose: " << option1.name << "!\n";
            option1.effect(player);
            break;
        case 2:
            std::cout << "You chose: " << option2.name << "!\n";
            option2.effect(player);
            break;
        case 3:
        default:
            std::cout << "You chose to pass.\n";
            break;
    }

    std::cout << "Press Enter to continue...\n";
    std::cin.ignore();
    std::cin.get();
}
