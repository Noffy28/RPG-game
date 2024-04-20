#ifndef ENEMY_H
#define ENEMY_H
#include <string>

class Enemy{
private:
    std::string _name;
    int _xpdrop;
    int _level;
    int _hp;
    int _strength;

public:
    Enemy(std::string Name = "Hero", int Xpdrop = 0, int Level = 1, int Hp = 10, int Strength = 2):
        _name(Name),
        _xpdrop(Xpdrop),
        _level(Level),
        _hp(Hp),
        _strength(Strength){}

    std::string getName(){
        return _name;
    }

    int getXp(){
        return _xpdrop;}

    int getLevel(){
        return _level;
    }

    int getHp(){
        return _hp;
    }

    int getStrength(){
        return _strength;
    }

    void setName(std::string newName){
        _name = newName;
    }

    void setXp(int newXp){
        _xpdrop = newXp;
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

    int dealDamage(){
        return _strength;
    }

};

#endif // ENEMY_H
