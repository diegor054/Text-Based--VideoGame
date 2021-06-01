#ifndef __ATTACKER_HPP__
#define __ATTACKER_HPP__

#include "Player.hpp"

//implement attacker class
class Attacker : public Player {
 private:
    string SwordType;
    
 public:
    Attacker() {
        name = "Null";
        characterType = "Attacker";
        health = maxHealth = baseHealth = 100;
        attackStrength = baseAttackStrength = 10;
        xp = currentXP = playerLevel = 0;
        refresh(false);
        weaponType = "Sword";
        SwordType = "Bronze";
    }
    Attacker(string &name_, int xp_) {
        name = name_;
        characterType = "Attacker";
        health = maxHealth = baseHealth = 100;
        attackStrength = baseAttackStrength = 10;
        xp = playerLevel = 0;
        currentXP = xp_;
        refresh(true);
        weaponType = "Sword";
        SwordType = "Bronze";
    }
    ~Attacker() = default;
    string attackMessage(BaseCharacter* opp) {
        int r = (rand() % 3);
        if (r == 0) return currentMessage = name + " had fun destroying " + opp->getName() + " with their " + SwordType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else if (r == 1) return currentMessage = name + " slashed " + opp->getName() + " with their " + SwordType + " " + weaponType + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " attacked " + opp->getName() + " with their " + SwordType + " " + weaponType + damageMessage(opp->getLatestDamage()); 
    }
};

#endif

