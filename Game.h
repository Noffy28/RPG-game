#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "datamanager.h"
#include "hero.h"



void createCharacter(){
    std::string Name;
    std::cout << "Name Your Character: " << std::endl;
    std::cin >> Name;

    Hero player(Name);
    player.getStats();

}

void loadHero(){
    std::string Name;
    std::cout << "What Character To Be Loaded: " << std::endl;
    std::cin >> Name;
    QSqlDatabase db;
    openDatabase(db);
    Hero player;
    player.loadCharacter(Name); //Is it valid checker???
    player.getStats();
    closeDatabase(db);
}

void saveGame(Hero& player){
    std::cout << "Saving game... " << std::endl;
    QSqlDatabase db;
    openDatabase(db);

    player.saveCharacter();

    closeDatabase(db);
}

bool mainMenu(Hero& player){
    bool menuon = true;
    while(menuon){
        int input;
        std::cout << "Welcome to my Game!" << std::endl;
        std::cout << "(1) Create New Character" << std::endl;
        std::cout << "(2) Load Game" << std::endl;
        std::cout << "(3) Exit Game" << std::endl;
        std::cout << "Please enter choice: " << std::endl;
        std::cin >> input;

            switch(input){
            case 1:
                createCharacter();
                menuon = false;
                break;
            case 2:
                loadHero();
                break;
            case 3:
                std::cout << "Thank you for playing" << std::endl;
                menuon = false;
                return true;
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;

            }
            return false;
        }
    }

bool gameMenu(Hero& player){
    bool gameon = true;
    while(gameon){
        int input;
        std::cout << "Your Options Are: " << std::endl;
        std::cout << "(1) Fight Monsters" << std::endl;
        std::cout << "(2) Save And Exit" << std::endl;
        std::cout << "Please enter choice: " << std::endl;
        std::cin >> input;

        switch(input){
        case 1:
            //battlefunction();
            break;
        case 2:
            saveGame(player);
            return true;
            break;
        default:
            std::cout << "Invalid choice, try again" << std::endl;

        }
        return false;
    }

}


#endif // GAME_H
