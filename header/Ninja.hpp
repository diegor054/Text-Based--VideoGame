#ifndef __NINJA_HPP__
#define __NINJA_HPP__

#include "Player.hpp"

class Ninja : public Player {
 private:
    string knifeType; //goes bronze, silver, gold, diamond
 public:
    Ninja() {
        name = "Null";
        characterType = "Ninja";
        health = maxHealth = 100;
        attackStrength = 8;
        xp = currentXP = playerLevel = 0;
        weaponType = "Knife";
        knifeType = "Bronze";
    }
    ~Ninja() = default;
    string attackMessage(BaseCharacter* opp) {
        return currentMessage = name + " had fun yeeting " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());
    }
};
                                                                                                                                   
#endif
