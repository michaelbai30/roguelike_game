#include "player.h"
#include <iostream>
#include <limits>

#include "player.h"
#include "stats.h"
#include <iostream>
#include <limits>

// player is derived from character
Player::Player(const std::string& name, const Stats& stats)
    : Character(name, 30, stats) {inventory["Potion"] = 1;}  // Set base HP to 30 

std::map<std::string, int>& Player::getInventory() {
    return inventory;
}

void Player::heal(int amount){
    hp += amount;
    if (hp > maxHP) hp = maxHP;
}

Stats &Player::getStats(){
    return stats;
}

void Player::modifyMaxHP(int amount){
    maxHP += amount;
    if (maxHP < 1) maxHP = 1;

    hp += amount;
    if (hp > maxHP){
        hp = maxHP;
    }
    if(hp < 0) hp = 0;
}
    
Player createPlayer(){
    std::string name;
    std::string classChoice;
    Stats stats;
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, name);

    std::cout << "\nChoose your class:\n";
    std::cout << "1. Warrior\n";
    std::cout << "2. Mage\n";
    std::cout << "3. Tank\n";
    std::cout << "4. Ninja\n";

    int choice;
    std::cin >> choice;
    std::cin.ignore(); // clear newline

    switch(choice){
        case 1:
            stats.strength = 8;
            stats.endurance = 6;
            stats.intelligence = 2;
            stats.willpower = 4;
            stats.speed = 4;
            stats.charisma = 2;
            stats.luck = 4;
            classChoice = "Warrior";
            break;

        case 2:
            stats.strength = 2;
            stats.endurance = 4;
            stats.intelligence = 8;
            stats.willpower = 5;
            stats.speed = 5;
            stats.charisma = 2;
            stats.luck = 4;
            classChoice = "Mage";
            break;

        case 3:
            stats.strength = 5;
            stats.endurance = 8;
            stats.intelligence = 2;
            stats.willpower = 7;
            stats.speed = 2;
            stats.charisma = 3;
            stats.luck = 3;
            classChoice = "Tank";
            break;

        case 4:
            stats.strength = 6;
            stats.endurance = 3;
            stats.intelligence = 4;
            stats.willpower = 3;
            stats.speed = 7;
            stats.charisma = 1;
            stats.luck = 6;
            classChoice = "Rogue";
            break;
    }

    calculateDerivedStats(stats);
    std::cout << "Welcome, " << name << " the " << classChoice << std::endl;   
    return Player(name, stats);


}
// TODO: Need to balance for gameplay 
// character creation

/*
Player createPlayer(){
    std::string name;
    Stats stats;
    const int totalPoints = 21;
    std::cout << "Enter your character's name: ";
    std::getline(std::cin, name);
    
    int remaining = totalPoints;

    while (remaining > 0){
        std::cout << "\nPoints remaining: " << remaining << "\n";
        std::cout << "Assign points to each stat:\n";
        std::cout << "Strength (Attack): "; std::cin >> stats.strength;
        std::cout << "Endurance (Physical Resist): "; std::cin >> stats.endurance;
        std::cout << "Intelligence (Magic Dmg): "; std::cin >> stats.intelligence;
        std::cout << "Willpower (Magic Resist): "; std::cin >> stats.willpower;
        std::cout << "Speed (Initiative/Dodge): "; std::cin >> stats.speed;
        std::cout << "Charisma (Shop Prices): "; std::cin >> stats.charisma;
        std::cout << "Luck (Crit Chance): "; std::cin >> stats.luck;
        
    int totalUsed =
            stats.strength + stats.endurance + stats.charisma + stats.luck +
            stats.willpower + stats.intelligence + stats.speed;

    if (totalUsed > totalPoints){
        std::cout << "\nToo many points used. Try again.\n";
        stats = Stats(); // reset 
        std::cin.clear(); // reset cin buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else{
        remaining = totalPoints - totalUsed;
        if (remaining > 0) {
                std::cout << "\nYou still have " << remaining << " points left.\n";
                char choice;
                std::cout << "Redo allocation? (y/n): ";
                std::cin >> choice;
                std::cin.ignore(); // clear newline
                if (choice == 'y' || choice == 'Y') {
                    stats = Stats();
                    remaining = totalPoints;
                }
            }
            else{
                break;
            }
    }      
    
    }
    calculateDerivedStats(stats);
    return Player(name, stats);
}
    */