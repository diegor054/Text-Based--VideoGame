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
        int r = (rand() % 5);
        if (r == 0) return currentMessage = name + " had fun deleting " + opp->getName() + " with their " + wandType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else if (r == 1) return currentMessage = name + " had fun attacking " + opp->getName() + " with their " + wandType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else if (r == 2) return currentMessage = name + " had fun laughing at " + opp->getName() + " while they suffered from the attack" + damageMessage(opp->getLatestDamage());
        else if (r == 3) return currentMessage = name + " used their magical powers on " + opp->getName() + " with their " + wandType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " swished " + opp->getName() + " with their " + wandType + " " + weaponType + damageMessage(opp->getLatestDamage());
    }
};
                                                             
#endif

