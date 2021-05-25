#ifndef __ATTACKER_HPP__
#define __ATTACKER_HPP__

#include "Player.hpp"

//implement attacker class
class Attacker : public Player {
 private:
	string SwordType;
	
 public:
	Attacker() {
		health = 100;
		xp = 0;
		weaponType = "Sword";
		playerTypeLevel = 0;
		SwordType = "Bronze";
	}
	void Upgrade() override {
		//implement
	}
	void setMaxHealth() override {
	    health = 100;
	}
	void setHealth(int x) { //used for when player is attacked
		this->health += x;
	}
	BaseCharacter* attack(vector<BaseCharacter*> charList) override {
		//implement
	}
	int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { return 0; } //fixme
};

#endif

