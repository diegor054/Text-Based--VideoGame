#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Opponent.hpp"

class BaseCharacter {
 private:
    string name;
    int health;
    int attackStrength;
 public:
    BaseCharacter() { }  
    virtual void attack(vector<Opponent*> oppList) = 0;
    void printHealth() const {
    int totalLines = 10;
    int lines = health / totalLines;
    cout << "[";
    for (int i = 0; i < totalLines; i++){
	    if (i < lines) cout << '|';
        else cout << ' ';
    }
    cout << "]  " << health << " remaining health" << endl;
};

#endif
