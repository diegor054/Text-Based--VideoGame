#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class BaseCharacter {
 protected:
    string name;
    string characterType;
    int health;
    int maxHealth;
    int attackStrength;
    int xp;
    int latestDamage;
    string currentMessage;
    void setAttackStrength(int a) { attackStrength = a; }

 public:
    BaseCharacter() { }
    ~BaseCharacter() = default; 
    virtual BaseCharacter* attack(vector<BaseCharacter*> oppList, int attackerIndex) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
    virtual string attackMessage(BaseCharacter* opp) = 0;
    string getHealthBar() const {
        int totalLines = 10;
        int lines = (100 * (health / maxHealth)) / totalLines;
        string healthBar = "[";
        for (int i = 0; i < totalLines; i++) {
	        if (i < lines) healthBar += "|";
            else healthBar += " ";
        }
        return healthBar += "]";
    }
    void setName(string n) { name = n; }
    void setType(string t) { characterType = t; }
    void setHealth(int h) { health = h; }
    void setXP(int x) { xp = x; }
    string getName() { return name; }
    string getType() { return characterType; }
    int getHealth() { return health; }
    int getXP() { return xp; }
    int getLatestDamage() { return latestDamage; }
    int getAttackStrength() { return attackStrength; }
};

#endif
