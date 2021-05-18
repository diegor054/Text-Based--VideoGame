fndef __GOBLINS_HPP__
#define __GOBLINS_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Fairies: public Opponent {
 private:

 public:
    Fairies() {
		opponentLevel = 1;
		attackStyle = "Pixie dust";
		health = 50;
		name = "Fairy;
		attackStrength = 3;
	}
    void attack(vector<Opponent*> opp) override {
    	if(this->health > 0){
        	opp.at(0)->setHealth(attackStrength * -1);
        	damageMessages(attackStrength);
        }
	}
	void damageMessages(int damage) {
		int num = (rand() % 3) + 1;
		if(num == 1) {
			cout << "Fairy sprinkles you and deals " << damage << " damage!" << endl;
		}
		else if(num == 2) {
			cout << "Fairy hit you hard! You lost " << damage << " health!" << endl;; 
		}
		else {
			cout << "Fairy is very mad at you and sprinkled you for " << damage << " health!" << endl;
		}
	}
};

#endif
