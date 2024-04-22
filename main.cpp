#include <iostream>
#include <string>
#include <QString>
#include "datamanager.h"
#include "hero.h"
#include "enemy.h"
#include "Game.h"





int main() {
    Hero player;

    if(mainMenu(player)){
        return 0;
    }

    gameMenu(player);
    return 0;
}
