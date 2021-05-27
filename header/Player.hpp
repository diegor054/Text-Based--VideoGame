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
	void UpdateLevel() {
		xp += currentXP;
		currentXP = 0;
		playerLevel = -3.01 + 0.867 * log(xp); //L0 = 0, L1 = 100, L2 = 333, L3 = 1000, L4 = 3333 ...
		if (playerLevel < 0) playerLevel = 0;
	}
	void setMaxHealth() { health = maxHealth; }; 	
};

#endif
