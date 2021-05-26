#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BaseCharacter {
 protected:
    string name;
    int health;
    int attackStrength;
    int maxhealth;
    string characterType;

 public:
    BaseCharacter() { }  
    virtual BaseCharacter* attack(vector<BaseCharacter*> oppList) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
    void printHealth() const {
        int totalLines = 10;
        int lines = (100*(health / maxhealth))/totalLines ;
        cout << "[";
        for (int i = 0; i < totalLines; i++) {
	        if (i < lines) cout << '|';
            else cout << ' ';
        }
        cout << "]  " << health << " remaining health" << endl;
    }
    void setName(string n) { name = n; }
    void setType(string t) { characterType = t; }
    void setHealth(int h) { health = h; }
    string getName() { return name; }
    string getType() { return characterType; }
    int getHealth() { return health; }
    int getLatestDamage() { return -1; } //fix
    int getAttackStrength() { return attackStrength; }
};

#endif
