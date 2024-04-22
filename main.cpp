#include <iostream>
#include <string>
#include <QString>
#include "datamanager.h"
#include "hero.h"
#include "enemy.h"

int mainMenu(){
    int input;
    std::cout << "Welcome to my Game, this is the menu text code" << std::endl;
    std::cout << "(1) Start Game" << std::endl;
    std::cout << "(2) Load Game" << std::endl;
    std::cout << "(3) Exit Game" << std::endl;
    std::cout << "Please enter choice: " << std::endl;
    std::cin >> input;
    return input;
}




int main() {
    QSqlDatabase db;
    Hero testboy;
    Enemy testEnemy1("Hest",4,100,1);

    openDatabase(db);


    //deleteCharacter("test");

    closeDatabase(db);

    /*while(gameon){
        int :nameinput = mainMeny();

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
}
