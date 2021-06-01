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
        health = maxHealth = baseHealth = 100;
        attackStrength = baseAttackStrength = 8;
        xp = currentXP = playerLevel = 0;
        refresh(false);
        weaponType = "Knife";
        knifeType = "Bronze";
    }
    Ninja(string &name_, int xp_) {
        name = name_;
        characterType = "Ninja";
        health = maxHealth = baseHealth = 100;
        attackStrength = baseAttackStrength = 8;
        xp = playerLevel = 0;
        currentXP = xp_;
        refresh(true);
        weaponType = "Knife";
        knifeType = "Bronze";
    }
    ~Ninja() = default;
    string attackMessage(BaseCharacter* opp) {
        int r = (rand() % 5);
        if (r == 0) return currentMessage = name + " had fun yeeting " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else if (r == 1)  return currentMessage = name + " had fun destroying " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else if (r == 2)  return currentMessage = name + " did not have mercy for " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (r == 3)  return currentMessage = name + " had fun wrecking " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " attacked " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());    
    }
};
                                                                                                                                   
#endif
