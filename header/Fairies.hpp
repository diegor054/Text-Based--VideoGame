#ifndef __FAIRIES_HPP__
#define __FAIRIES_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Fairies: public Opponent {
 private:

 public:
    Fairies() {
		name = characterType = "Fairy";
		health = maxHealth = 50;
		attackStrength = 3;
		xp = opponentLevel = 0;		
		attackStyle = "Pixie dust";
	}
	string attackMessage(BaseCharacter* opp) override {
		int message = rand() % 3;
		if (message == 0) return currentMessage = name + " sprinkles " + opp->getName() + damageMessage(opp->getLatestDamage());
		else if (message == 1) return currentMessage = "Fairy hit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
		else return currentMessage = "Fairy is very mad at you and sprinkled " + opp->getName() + damageMessage(opp->getLatestDamage());
	}
};

#endif
