#include <iostream>
#include "hero.h"
#include "enemy.h"

int mainMeny(){
    int input;
    std::cout << "Welcome to my Game, this is the meny text code" << std::endl;
    std::cout << "(1) Start Game" << std::endl;
    std::cout << "(2) Load Game" << std::endl;
    std::cout << "(3) Exit Game" << std::endl;
    std::cout << "Please enter choice: " << std::endl;
    std::cin >> input;
    return input;
}


int main() {
    bool gameon = true;

    Hero h;

    std::cout << h.getLevel() << std::endl;

    /*while(gameon){
        int input = mainMeny();

        switch(input){
        case 1:
            std::cout << "1. text..." << std::endl;
            break;
        case 2:
            std::cout << "2. text..." << std::endl;
            break;
        case 3:
            std::cout << "3. Goodbye!" << std::endl;
            gameon = false;
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }

    }*/


    return 0;
}
