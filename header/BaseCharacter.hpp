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
    int baseHealth;
    int attackStrength;
    int baseAttackStrength;
    int xp;
    int level;
    int latestDamage;
    string currentMessage;
    bool outputMessages = true;
    void setAttackStrength(int a) { attackStrength = a; }

 public:
    BaseCharacter() { }
    ~BaseCharacter() = default; 
    virtual BaseCharacter* attack(vector<BaseCharacter*> oppList, int attackerIndex) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) { 
        if (health - damage > 0) {
            this->setHealth(health - damage);
            return latestDamage = damage;
        }
        else {
            latestDamage = health;
            this->setHealth(0);
            return latestDamage;
        }
    }
    virtual string attackMessage(BaseCharacter* opp) = 0;
    virtual string getHealthBar() const {
        int totalLines = 10;
        int lines = ((100.0 * health) / maxHealth) / totalLines;
        string healthBar = "[";
        for (int i = 0; i < totalLines; i++) {
            if (i < lines) healthBar += "|";
            else healthBar += " ";
        }
        return healthBar += "]";
    }
    virtual void setName(string n) { name = n; }
    virtual void setType(string t) { characterType = t; }
    virtual void setHealth(int h) { health = h; }
    virtual void setXP(int x) { xp = x; }
    virtual void setOutputStatus(bool o) { outputMessages = o; }
    virtual string getName() { return name; }
    virtual string getType() { return characterType; }
    virtual int getHealth() { return health; }
    virtual int getXP() { return xp; }
    virtual bool getOutputStatus() { return outputMessages; }
    virtual int getLatestDamage() { return latestDamage; }
    virtual int getAttackStrength() { return attackStrength; }
    virtual void refresh(bool keepXP) = 0;
};

#endif
