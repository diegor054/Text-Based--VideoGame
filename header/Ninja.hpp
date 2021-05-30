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
        return currentMessage = name + " had fun yeeting " + opp->getName() + " with their " + knifeType + " " + weaponType + damageMessage(opp->getLatestDamage());
    }
};
                                                                                                                                   
#endif
