#ifndef __NINJA_HPP__
#define __NINJA_HPP__

#include "Player.hpp"

class Ninja: public Player {
private:
string knifeType; //goes wood, steel, gold, diamond. used just for show not any purpose. propotional to playerTypeLevel
public:
Ninja() {
health = 100;
xp = 0;
weaponType = "Knife";
playerTypeLevel = 0;
knifeType = "Bronze";
}
void Upgrade() override {
//implement
}
void setMaxHealth() override {
health = 100;
}
void setHealth(int x){
this->health += x;
}
void attack(vector<Opponent*> opp) override {
//implement
}
};                                                           		    	                                                          
#endif
