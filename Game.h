#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "datamanager.h"
#include "hero.h"
#include "enemy.h"

class Game{
private:
    Hero player;
    Enemy monster;
public:
    Hero createCharacter(){
        std::string Name;
        std::cout << "Name Your Character: " << std::endl;
        std::cin >> Name;

        player = Hero(Name);
        player.getStats();
        return player;
    }

    Hero loadHero(){
        std::string Name;
        std::cout << "What Character To Be Loaded: " << std::endl;
        std::cin >> Name;
        QSqlDatabase db;
        openDatabase(db);

        player.loadCharacter(Name); //Is it valid checker???
        player.getStats();
        closeDatabase(db);
        return player;
    }

    void saveGame(){
        std::cout << "Saving game... " << std::endl;
        QSqlDatabase db;
        openDatabase(db);
        player.deleteCharacter(player.getName());
        player.saveCharacter();

        closeDatabase(db);
    }

    Enemy loadMonster(std::string enemyName){
        QSqlDatabase db;
        openDatabase(db);

        monster.loadEnemy(enemyName);
        closeDatabase(db);
        return monster;

    }
    void battleText(){
        std::cout << player.getName() << " With " << player.getHp() << " Hp And "  << player.getStrength() << " Strength" << std::endl;
        std::cout << "Is Fighting " << monster.getName() << " With " << monster.getHp() << " Hp And " << monster.getStrength() << " Strength" << std::endl;
    }

    void battleFunction(){
        bool battleOn = true;
        while(battleOn){
            int input;
            std::cout << "Press (1) to fight" << std::endl;
            std::cin >> input;

            switch(input){
            case 1:
                monster.takeDamage(player.dealDamage());
                player.takeDamage(monster.dealDamage());
                std::cout << player.getName() << " With " << player.getHp() << " Hp" << std::endl;
                std::cout << monster.getName() << " Wtih " << monster.getHp() << " Hp" << std::endl;

                if(player.getHp() == 0){
                    std::cout << "You Died" << std::endl;
                    battleOn = false;
                    break;
                }

                else if(monster.getHp() == 0){
                    std::cout << "You Have Slain the " << monster.getName() << std::endl;
                    player.gainXp(monster.getXpdrop());
                    player.healDamage();
                    battleOn = false;
                    break;
                }
                break;


            default:
                std::cout << "Invalid choice, try again" << std::endl;
            }

        }

    }


    bool mainMenu(){
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
                break;
            case 2:
                loadHero();
                break;
            case 3:
                std::cout << "Thank you for playing" << std::endl;
                return true;
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;

            }
            return false;
        }
        return true;
    }



    bool gameMenu(){
        bool gameon = true;
        while(gameon){
            int input;
            std::cout << "Your Options Are: " << std::endl;
            std::cout << "(1) Fight Monsters" << std::endl;
            std::cout << "(2) Get Stats" << std::endl;
            std::cout << "(9) Save And Exit" << std::endl;
            std::cout << "Please Enter choice: " << std::endl;
            std::cin >> input;

            switch(input){
            case 1:
                pickEnemy();
                battleFunction();
                break;
            case 2:
                player.getStats();
                continue;
            case 9:
                saveGame();
                return true;
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;

            }
        }
        return false;
    }

    bool pickEnemy(){
        bool pickon = true;
        while(pickon){
            int input;
            std::cout << "Pick An Enemy To Fight " << std::endl;
            std::cout << "(1) Hest" << std::endl;
            std::cout << "(2) Weak Goblin" << std::endl;
            std::cout << "(3) Strong Goblin" << std::endl;
            std::cout << "(4) Stronger Goblin" << std::endl;
            std::cout << "(5) Goblin King" << std::endl;
            std::cout << "(6) Monkey King" << std::endl;
            std::cout << "(7) Unicorn" << std::endl;
            std::cout << "(8) Dragon" << std::endl;
            std::cout << "(9) Save And Exit" << std::endl;
            std::cout << "Please Enter choice: " << std::endl;
            std::cin >> input;

            switch(input){
            case 1:
                loadMonster("Hest");
                battleText();
                pickon = false;
                break;
            case 2:
                loadMonster("Weak Goblin");
                battleText();
                pickon = false;
                break;
            case 3:
                loadMonster("Strong Goblin");
                battleText();
                pickon = false;
                break;
            case 4:
                loadMonster("Stronger Goblin");
                battleText();
                pickon = false;
                break;
            case 5:
                loadMonster("Goblin King");
                battleText();
                pickon = false;
                break;
            case 6:
                loadMonster("Monkey King");
                battleText();
                pickon = false;
                break;
            case 7:
                loadMonster("Unicorn");
                battleText();
                pickon = false;
                break;
            case 8:
                loadMonster("Dragon");
                battleText();
                pickon = false;
                break;
            case 9:
                saveGame();
                return true;
                break;
            default:
                std::cout << "Invalid choice, try again" << std::endl;

            }

        }
        return true;
    }


};





#endif // GAME_H
