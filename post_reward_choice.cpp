#include "post_reward_choice.h"
#include <iostream>

NextPhase chooseNextPhase(){

    std::cout << "\n-- Proceed to Next Phase --\n";
    std::cout << "1. Battle\n";
    std::cout << "2. Event\n";
    std::cout << "> ";

    int choice;
    std::cin >> choice;
    
    if (choice == 2){
        return NextPhase::EVENT;
    }
    return NextPhase::BATTLE;
}