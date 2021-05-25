#ifndef __HEALER_HPP__
#define __HEALER_HPP__

#include "Player.hpp"

//implement healer class

class Healer: public Player {
 private:
    string wandType; //goes wood, steel, gold, diamond. used just for show not any purpose. propotional to playerTypeLevel
 public:
    Healer() {
        health = 200;
        xp = 0;
        weaponType = "Wand";
        playerTypeLevel = 0;
        wandType = "Wood";
    }
    void Upgrade() override {
        //implement
    }
    void setMaxHealth() override {
        health = 200;
    }
	void setHealth(int x){
	    this->health += x;
	}
    BaseCharacter* attack(vector<BaseCharacter*> charList) override {
		//implement
	}
    int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { return 0; } //fixme
};
                                                             
#endif

