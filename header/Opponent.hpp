#ifndef __OPPONENT_HPP__
#define __OPPONENT_HPP__

#include "BaseCharacter.hpp"

class Opponent : public BaseCharacter {
 protected:
	int opponentLevel;
	string attackStyle;
 public:
	Opponent() { }
	~Opponent() = default;
	BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
		int opponentIndex = 0;
		charList.at(opponentIndex)->defend(charList, attackerIndex, this->attackStrength);
	}
	int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { 
		if (health - damage > 0) this->setHealth(health - damage);
		else this->setHealth(0);
		return damage;
	}
};

#endif
