#include "combat.h"
#include "player.h"
#include "character.h"
#include "stats.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <thread>
#include <chrono>
#include <vector>

// colors
#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#ifdef _WIN32
#define CLEAR "CLS"
#else
#define CLEAR "clear"
#endif

// adjust if needed
int wait_for = 3000;

void animateAction(const std::vector<std::string> &frames, int delayMs = 150) {
    for (const auto &frame : frames) {
        std::cout << "\r" << frame << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
    }
    std::cout << "\r" << std::string(frames.back().size(), ' ') << "\r"; // clear line after animation
}

// generate 20 block visual hp bar
std::string getHPBar(int current, int max) {
    const int totalBars = 20;
    float ratio = static_cast<float>(current) / max;
    int filled = static_cast<int>(ratio * totalBars);
    std::string bar = "[";
    for (int i = 0; i < totalBars; ++i) {
        bar += (i < filled) ? "█" : "-";
    }
    bar += "]";
    return bar;
}

// helper function to calculate damage
int calculateDamage(int atk, int def, bool defending) {
    int dmg = atk - def;
    if (dmg < 0) dmg = 0;
    if (atk > 0 && dmg == 0) dmg = 1; // atks can do at least 1 dmg
    if (defending) {
        dmg = static_cast<int>(dmg * 0.3);
        if (dmg == 0 && atk > 0) dmg = 1; // ensure defending doesn't reduce damage below 1
    }
    return dmg;
}

// crit check
bool isCriticalHit(int critChance) {
    return critChance > (rand() % 100);
}

// UI menu
void showMenu() {
    std::cout << "\nChoose action:\n";
    std::cout << "1. Attack\n";
    std::cout << "2. Magic (Fireball)\n";
    std::cout << "3. Defend\n";
    std::cout << "4. Item\n";
    std::cout << "5. Assess Enemy\n";
    std::cout << "6. See Stats\n";
    std::cout << "> ";
}

// stat display when assessed
void printStats(Character& c) {
    Stats& s = c.getStats();
    std::cout << "\n[" << c.getName() << "'s Stats]\n";
    std::cout << "HP: " << c.getHP() << "\n";
    std::cout << "Attack: " << s.attack << " | Armor: " << s.armor << "\n";
    std::cout << "Magic Dmg: " << s.magicDmg << " | Magic Resist: " << s.magicResist << "\n";
    std::cout << "Speed: " << s.speed << " | Crit Chance: " << s.critChance << "%\n";
    std::cout << "Charisma: " << s.charisma << "\n";
}

static int turnNumber = 1;

// player turn logic
void playerTurn(Player &player, Character &enemy, int turnNumber) {
    system(CLEAR); 

    std::cout << "\n--- Turn " << turnNumber << " --- (" << player.getName() <<"'s Turn)\n";

    player.setDefending(false);

    std::cout << GREEN << "[" << player.getName() << " HP: " << player.getHP() << " " << getHPBar(player.getHP(), player.getMaxHP()) << "]" << RESET << " | ";
    std::cout << RED << "[" << enemy.getName() << " HP: " << enemy.getHP() << " " << getHPBar(enemy.getHP(), enemy.getMaxHP()) << "]" << RESET << "\n";

    showMenu();
    int choice;
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // flush newline

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    // actions 
    switch (choice) {
        case 1: { // Attack
            std::cout << "You strike with your weapon!\n";
            animateAction({"-", "--", "---", "--->", "---->", "----->"}, 250);

            int dmg = calculateDamage(player.getStats().attack, enemy.getStats().armor, enemy.isDefending());
            if (isCriticalHit(player.getStats().critChance)) {
                dmg = static_cast<int>(dmg * 2);
                std::cout << "Critical Hit!\n";
            }
            enemy.takeDamage(dmg);
            std::cout << "You dealt " << dmg << " damage.\n";
            break;
        }
        case 2: { // Magic
            std::cout << "You cast Fireball!\n";
            animateAction({"~", "~~", "~~~", "~~~~>>>", "~~~~~>>>", "~~~~~~>>>"}, 250);
            int dmg = calculateDamage(player.getStats().magicDmg, enemy.getStats().magicResist, enemy.isDefending());
            if (isCriticalHit(player.getStats().critChance)) {
                dmg = static_cast<int>(dmg * 2);
                std::cout << "Critical Hit!\n";
            }
            enemy.takeDamage(dmg);
            std::cout << "It deals " << dmg << " magic damage.\n";
            break;
        }
        case 3: // Defend
            std::cout << "You prepare to block incoming attacks.\n";
            player.setDefending(true);
            break;
        case 4: { // Item
            auto& inventory = player.getInventory();
            if (inventory["Potion"] > 0) {
                inventory["Potion"]--;
                player.heal(10);
                std::cout << "You use a potion and heal 10 HP.\n";
            } else {
                std::cout << "You have no Potions left!\n";
                std::this_thread::sleep_for(std::chrono::milliseconds(wait_for));
                playerTurn(player, enemy, turnNumber); // retry turn if no potions
                return;
            }
            break;
        }
        case 5: // Assess
            printStats(enemy);
            std::this_thread::sleep_for(std::chrono::milliseconds(6000));
            return;
        case 6: 
            printStats(player);
            std::this_thread::sleep_for(std::chrono::milliseconds(6000));
            playerTurn(player, enemy, turnNumber);
        default:
            std::cout << "Invalid action. Try again.\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            playerTurn(player, enemy, turnNumber);
            return;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(wait_for));
}

// enemy turn logic
// modify this for different enemy types 
void enemyTurn(Character &enemy, Player &player, int turnNumber) {
    system(CLEAR); // clear screen before enemy turn
    std::cout << "\n--- Turn " << turnNumber << " --- (" << enemy.getName() <<"'s Turn)\n";

    if (!enemy.isAlive()) return;
    enemy.setDefending(false);

    std::cout << GREEN << "[" << player.getName() << " HP: " << player.getHP() << " " << getHPBar(player.getHP(), player.getMaxHP()) << "]" << RESET << " | ";
    std::cout << RED << "[" << enemy.getName() << " HP: " << enemy.getHP() << " " << getHPBar(enemy.getHP(), enemy.getMaxHP()) << "]" << RESET << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(wait_for));

    int choice = rand() % 2;
    if (choice == 0) {
        std::cout << enemy.getName() << " attacks!\n";
        int dmg = calculateDamage(enemy.getStats().attack, player.getStats().armor, player.isDefending());
        if (dmg <= 0 && enemy.getStats().attack > 0) dmg = 1;
        player.takeDamage(dmg);
        std::cout << player.getName() << " took " << dmg << " damage.\n";
    }
    else {
        std::cout << enemy.getName() << " defends.\n";
        enemy.setDefending(true);
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(wait_for));
}

// round logic with speed based order and proper defend reset
void combatRound(Player &player, Character &enemy, int turnNumber) {
    system(CLEAR);
    int playerSpeed = player.getStats().speed;
    int enemySpeed = enemy.getStats().speed;

    if (playerSpeed >= enemySpeed) {
        playerTurn(player, enemy, turnNumber);
        if (enemy.isAlive()) enemyTurn(enemy, player, turnNumber);
    } else {
        enemyTurn(enemy, player, turnNumber);
        if (player.isAlive()) playerTurn(player, enemy, turnNumber);
    }

    turnNumber++;
}
