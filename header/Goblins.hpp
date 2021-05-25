#ifndef __GOBLINS_HPP__
#define __GOBLINS_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Goblins: public Opponent {
 private:

 public:
    Goblins() {
		opponentLevel = 1;
		attackStyle = "Knife";
		health = 50;
		name = "Goblin";
		attackStrength = 2;
	}
    BaseCharacter* attack(vector<BaseCharacter*> charList) override {
    	if(this->health > 0){
        	charList.at(0)->setHealth(attackStrength * -1);
        	damageMessages(attackStrength);
        }
	}
	int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { return 0; } //fixme
	void damageMessages(int damage) {
		int num = (rand() % 3) + 1;
		if(num == 1) {
			cout << "Goblin knife you and took off " << damage << " damage!" << endl;
		}
		else if(num == 2) {
			cout << "Goblin hit you hard! You lost " << damage << " health!" << endl; 
		}
		else {
			cout << "Goblin is very mad at you and attacked you for " << damage << " health!" << endl;
		}
	}
};

#endif
