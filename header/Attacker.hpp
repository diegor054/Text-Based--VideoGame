#ifndef __ATTACKER_HPP__
#define __ATTACKER_HPP__
#include "BaseCharacter.hpp"

//implement attacker  class
class Attacker: public BaseCharacter{
	private:
	string SwordType;
	public:
	Attacker(): health(100),xp(0), weaponType("Sword"), playerTypeLevel(0), SwordType("Bronze") {}
	void Upgrade() override{
	//implement
	}
	void setMaxHealth() const override{
	health = 100;
	}
	void attack(vector<Opponent*> opp){
	//implement
	}

};
#endif

