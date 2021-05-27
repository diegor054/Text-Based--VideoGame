#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "BaseCharacter.hpp"

class Player : public BaseCharacter {
 protected:
	string weaponType;
	int playerLevel;
	int currentXP;
 public:
	Player() { }
	BaseCharacter* attack(vector<BaseCharacter*> charList) override {
		int numOpponents = charList.size() - 1;
		int opponentIndex = rand() % numOpponents + 1;
		charList.at(opponentIndex)->defend(charList, 0, this->attackStrength);
	}
	int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { 
		if (health - damage > 0) this->setHealth(health - damage);
		else this->setHealth(0);
		return damage;
	}
	virtual string attackMessage(BaseCharacter* opp) = 0;
	void setMaxHealth() { health = maxHealth; }
	void UpdateLevel() {
		xp += currentXP;
		currentXP = 0;
		playerLevel = -3.01 + 0.867 * log(xp); //L0 = 0, L1 = 100, L2 = 333, L3 = 1000, L4 = 3333 ...
		if (playerLevel < 0) playerLevel = 0;
	}	
};

#endif
