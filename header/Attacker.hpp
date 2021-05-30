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
    ~Attacker() = default;
    string attackMessage(BaseCharacter* opp) {
        return currentMessage = name + " had fun destroying " + opp->getName() + " with their " + SwordType + " " + weaponType + damageMessage(opp->getLatestDamage());
    }
};

#endif

