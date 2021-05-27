#ifndef __NINJA_HPP__
#define __NINJA_HPP__

#include "Player.hpp"

class Ninja : public Player {
 private:
    string knifeType; //goes bronze, silver, gold, diamond
 public:
    Ninja() {
        name = "Null";
        characterType = "Healer";
        health = maxHealth = 100;
        attackStrength = 8;
        xp = currentXP = playerLevel = 0;
        weaponType = "Knife";
        knifeType = "Bronze";
    }
    ~Ninja() = default;
};
                                                         		    	                                                          
#endif
