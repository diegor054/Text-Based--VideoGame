#ifndef __ZOMBIES_HPP__
#define __ZOMBIES_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Zombies: public Opponent {
 private:
	
 public:
    Zombies() {
        opponentLevel = 1; 
        attackStyle = "Teeth"; 
        health = 25; 
        name = "Zombie"; 
        attackStrength = 5;
    }
    BaseCharacter* attack(vector<BaseCharacter*> charList) override {//the idea of making player index 0 is good but wouldnt the vector have to be BaseCharacters since player isnt an 	//opoenent
    	if(this->health > 0){
        	charList.at(0)->setHealth(attackStrength * -1);
        	damageMessages(attackStrength);
        }
	}
	void damageMessages(int damage) {
        int num = (rand() % 3) + 1;
        if(num == 1) {
            cout << "Zombie bites you and deals " << damage << " damage!" << endl;
        }
        else if(num == 2) {
            cout << "ERRRR. Zombie bit you hard! You lost " << damage << " health!" << endl;
        }
        else {
            cout << "Zombie wants some fresh meat. He attacked you for " << damage << " health!" << endl;
        }
    }
};

#endif
