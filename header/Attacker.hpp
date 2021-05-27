#ifndef __ATTACKER_HPP__
#define __ATTACKER_HPP__

#include "Player.hpp"

//implement attacker class
class Attacker : public Player {
 private:
	string SwordType;
	
 public:
	Attacker() {
		name = "Null";
		characterType = "Attacker";
		health = maxHealth = 100;
		attackStrength = 10;
		xp = playerLevel = 0;
		weaponType = "Sword";
		SwordType = "Bronze";
	}
	void Upgrade() override {
		//implement
	}
	void setMaxHealth() override {
	    health = maxHealth;
	}
	void setHealth(int x) { //used for when player is attacked
		this->health += x;
	}
	BaseCharacter* attack(vector<BaseCharacter*> charList) override {
		int numOpponents = charList.size() - 1;
		int opponentIndex = rand() % numOpponents + 1;
		charList.at(opponentIndex)->defend(charList, 0, this->attackStrength); //fixme damage
	}
	int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { 
		if (health - damage > 0) this->setHealth(health - damage);
		else this->setHealth(0);
	}
};

#endif

