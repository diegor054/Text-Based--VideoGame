#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "BaseCharacter.hpp"

class Player : public BaseCharacter {
 protected:
	string weaponType;
	int xp;
	int playerTypeLevel;
 public:
	Player() { }
	virtual void Upgrade() = 0; //each playerType will have unique Upgrade
	virtual	void setMaxHealth() = 0; 
};

#endif
