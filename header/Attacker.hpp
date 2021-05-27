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
		xp = currentXP = playerLevel = 0;
		weaponType = "Sword";
		SwordType = "Bronze";
	}
	~Attacker() = default;
	string attackMessage(BaseCharacter* opp) {
		return currentMessage = name + " destroyed " + opp->getName() + damageMessage(opp->getLatestDamage());
	}
	string defendMessage() {
		//return name + " was deleted by " + damageMessage();
	}
};

#endif

