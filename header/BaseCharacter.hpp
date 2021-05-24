#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Opponent.hpp"

class BaseCharacter {
 protected:
    string name;
    int health;
    int attackStrength;
    int maxhealth;
    string characterType;

 public:
    BaseCharacter() { }  
    virtual void attack(vector<Opponent*> oppList) = 0;
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
    void setName(string n){ name = n; }
    void setType(string t){ characterType t; }
    string getName(){ return name; }
    string getType(){ return characterType; } 
};

#endif
