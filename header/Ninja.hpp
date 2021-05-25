#ifndef __NINJA_HPP__
#define __NINJA_HPP__

#include "Player.hpp"

class Ninja: public Player {
 private:
    string knifeType; //goes bronze, silver, gold, diamond
 public:
    Ninja() {
        health = 100;
        xp = 0;
        weaponType = "Knife";
        playerTypeLevel = 0;
        knifeType = "Bronze";
    }
    void Upgrade() override {
        //implement
    }
    void setMaxHealth() override {
        health = 100;
    }
    void setHealth(int x){
        this->health += x;
    }
    BaseCharacter* attack(vector<BaseCharacter*> charList) override {
		//implement
	}
};
                                                         		    	                                                          
#endif
