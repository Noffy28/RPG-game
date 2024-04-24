#include <iostream>
#include <string>
#include <QString>
#include "datamanager.h"
#include "hero.h"
#include "enemy.h"
#include "Game.h"





int main() {
    Game game;
    Hero test;
    //Enemy monster("Dragon",3000,100,10);
    //QSqlDatabase db;

    //openDatabase(db);
    //monster.saveEnemy();
    //closeDatabase(db);

    while(1){
        if(game.mainMenu()){
            break;
        }
        if(game.gameMenu()){
            break;
        }


    }
}
