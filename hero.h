#ifndef HERO_H
#define HERO_H
#include <iostream>
#include <string>
#include <QCoreApplication>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>

class Hero{
private:
    std::string _name;
    int _xp;
    int _level;
    int _hp;
    int _strength;

public:
    Hero(std::string Name = "Hero", int Xp = 0, int Level = 1, int Hp = 10, int Strength = 2):
        _name(Name),
        _xp(Xp),
        _level(Level),
        _hp(Hp),
        _strength(Strength){}

    std::string getName(){
        return _name;
    }

    int getXp(){
        return _xp;}

    int getLevel(){
        return _level;
    }

    int getHp(){
        return _hp;
    }

    int getStrength(){
        return _strength;
    }

    void getStats(){
        std::cout << getName() << "'s Stats:" << std::endl;
        std::cout << "Hp: " << getHp() << std::endl;
        std::cout << "Strength: " << getStrength() << std::endl;
        std::cout << "Level: " << getLevel() << std::endl;
        std::cout << "Xp: " << getXp() << std::endl;
    }

    void setName(std::string newName){
        _name = newName;
    }


    void setXp(int newXp){
        _xp = newXp;
    }

    void setLevel(int newLevel){
        _level = newLevel;
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

    void healDamage(){
        _hp = 8 +  _level * 2;
    }

    int dealDamage(){
        return _strength;
    }

    void gainXp(int xpGain){
        _xp = _xp + xpGain;
        if(_xp >= 1000 * _level){
            levelUp();
        }
    }

    void levelUp(){
        _xp = _xp - 1000 * _level;
        _level++;
        _hp = _hp + 2;
        _strength++;
        std::cout << _name << " Leveled Up!" << std::endl;
        getStats();
    }

    void loadCharacter(std::string characterName){
        QString _characterName = QString::fromStdString(characterName);
        QSqlQuery query;
        query.prepare("SELECT * FROM characterBase Where _name = :name");
        query.bindValue(":name", _characterName);


        if (!query.exec()) {
            qDebug() << "Failed to load character:" << query.lastError().text();

        }

        if (query.next()) {
            QString nameQString = query.value("_name").toString();
            std::string nameStdString = nameQString.toStdString();
            setName(nameStdString);
            setXp(query.value("_xp").toInt());
            setLevel(query.value("_level").toInt());
            setHp(query.value("_hp").toInt());
            setStrength(query.value("_strength").toInt());
        }
    }

    void saveCharacter(){
        QString name = QString::fromStdString(_name);

        QSqlQuery query;
        query.prepare("INSERT INTO characterBase (_name, _xp, _level, _hp, _strength) VALUES(:name, :xp, :level, :hp, :strength)");
        query.bindValue(":name", name);
        query.bindValue(":xp", _xp);
        query.bindValue(":level", _level);
        query.bindValue(":hp", _hp);
        query.bindValue(":strength", _strength);

        if (!query.exec()) {
            qWarning() << "Failed to save character:" << query.lastError().text();
        }


    }

    void deleteCharacter(std::string _name){
        QString name = QString::fromStdString(_name);

        QSqlQuery query;
        query.prepare("DELETE FROM characterBase WHERE _name = :name");
        query.bindValue(":name", name);

        if (!query.exec()) {
            qDebug() << "Failed to delete character:" << query.lastError().text();

        }
        qDebug() << "Character deleted successfully.";
    }


};

#endif // HERO_H
