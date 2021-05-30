#ifndef __HEALER_HPP__
#define __HEALER_HPP__

#include "Player.hpp"

//implement healer class

class Healer : public Player {
 private:
    string wandType; //goes wood, steel, gold, diamond. used just for show not any purpose. propotional to playerTypeLevel
 public:
    Healer() {
        name = "Null";
        characterType = "Healer";
        health = maxHealth = baseHealth = 200;
        attackStrength = baseAttackStrength = 8;
        xp = currentXP = playerLevel = 0;
        refresh(false);
        weaponType = "Wand";
        wandType = "Wood";
    }
    Healer(string &name_, int xp_) {
        name = name_;
        characterType = "Healer";
        health = maxHealth = baseHealth = 200;
        attackStrength = baseAttackStrength = 8;
        xp = playerLevel = 0;
        currentXP = xp_;
        refresh(true);
        weaponType = "wand";
        wandType = "Wood";
    }
    ~Healer() = default;
    string attackMessage(BaseCharacter* opp) {
        return currentMessage = name + " had fun deleting " + opp->getName() + " with their " + wandType + " " + weaponType + damageMessage(opp->getLatestDamage());
    }
};
                                                             
#endif

