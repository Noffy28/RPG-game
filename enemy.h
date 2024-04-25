#ifndef ENEMY_H
#define ENEMY_H
#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>


class Enemy{
private:
    std::string _name;
    int _xpdrop;
    int _hp;
    int _strength;

public:
    Enemy(std::string Name = "Enemy", int Xpdrop = 0, int Hp = 1, int Strength = 1):
        _name(Name),
        _xpdrop(Xpdrop),
        _hp(Hp),
        _strength(Strength){}

    std::string getName(){
        return _name;
    }

    int getXpdrop(){
        return _xpdrop;}

    int getHp(){
        return _hp;
    }

    int getStrength(){
        return _strength;
    }

    void setName(std::string newName){
        _name = newName;
    }

    void setXpdrop(int newXpdrop){
        _xpdrop = newXpdrop;
    }

    void setHp(int newHp){
        _hp = newHp;
    }

    void setStrength(int newStrength){
        _strength = newStrength;
    }

    void takeDamage(int damage){
        _hp = _hp - damage;
        if (_hp < 0){
            _hp = 0;
        }
    }

    int dealDamage(){
        return _strength;
    }

    void loadEnemy(){

        QSqlQuery query;
        query.prepare("SELECT _name, _hp, _strength, _xp from enemyBase");
        //query.bindValue(":name", _enemyName);

        if(query.exec()){
            std::cout << "Avaliable Enemies: " << std::endl;
            int count = 1;
            while(query.next()){
                std::string _name = query.value(0).toString().toStdString();
                int hp = query.value(1).toInt();
                int strength = query.value(2).toInt();

                std::cout << "(" << count << ")" << _name << " With: " << hp << " Hp And " << strength << " Strength" << std::endl;
                count++;
            }
            int choice;
            std::cout << "Choose Your Enemy: " << std::endl;

            std::cin >> choice;

            query.seek(choice -1);

            _name = query.value(0).toString().toStdString();
            _hp = query.value(1).toInt();
            _strength = query.value(2).toInt();
            _xpdrop = query.value(3).toInt();


        }






        if (!query.exec()) {
            qDebug() << "Failed to load enemy:" << query.lastError().text();

        }

    }

    void saveEnemy(){
        QString name = QString::fromStdString(_name);

        QSqlQuery query;
        query.prepare("INSERT INTO enemyBase (_name, _xp, _hp, _strength) VALUES(:name, :xp, :hp, :strength)");
        query.bindValue(":name", name);
        query.bindValue(":xp", _xpdrop);
        query.bindValue(":hp", _hp);
        query.bindValue(":strength", _strength);

        if (!query.exec()) {
            qWarning() << "Failed to save enemy:" << query.lastError().text();
        }
    }

    void deleteEnemy(std::string _name){
        QString name = QString::fromStdString(_name);

        QSqlQuery query;
        query.prepare("DELETE FROM enemyBase WHERE _name = :name");
        query.bindValue(":name", name);

        if (!query.exec()) {
            qDebug() << "Failed to delete Enemy:" << query.lastError().text();

        }
        qDebug() << "Enemy deleted successfully.";
    }

};

#endif // ENEMY_H
