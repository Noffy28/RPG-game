#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

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




int main(int argc, char *argv[]) {
    bool gameon = true;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/christofferbj/Workspace/Database/test1.db;");

    qDebug() << "File path:" << db.databaseName();

    if (!db.open()) {
        qWarning() << "Failed to open database:" << db.lastError().text();
        return 1;
    }




    QSqlQuery query(db);
    query.prepare("INSERT INTO gametest (_name, _xp, _level, _hp, _strength) VALUES(:name, :xp, :level, :hp, :strength)");
    query.bindValue(":name", "TestName");
    query.bindValue(":xp", 100);
    query.bindValue(":level", 5);
    query.bindValue(":hp", 80);
    query.bindValue(":strength", 15);

    if (!query.exec()) {
        qWarning() << "Failed to insert test data:" << query.lastError().text();
        return 1;
    }

    qDebug() << "Test data inserted successfully.";

    db.close();
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
}
