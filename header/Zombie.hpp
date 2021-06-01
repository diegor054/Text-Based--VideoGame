#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Zombie : public Opponent {
 private:
    
 public:
    Zombie() {
        name = characterType = "Zombie"; 
        health = maxHealth = baseHealth = 25;
        attackStrength = baseAttackStrength = 5;
        xp = opponentLevel = 0;
        refresh(false);
        attackStyle = "Teeth";
    }
    Zombie(int level) {
        name = characterType = "Zombie"; 
        baseHealth = 25;
        baseAttackStrength = 5;
        xp = opponentLevel = level;
        health = maxHealth = baseHealth * (1 + 0.1 * pow(opponentLevel, 1.6));
        attackStrength = baseAttackStrength * (1 + 0.1 * pow(opponentLevel, 1.6));
        refresh(false);
        attackStyle = "Teeth";
    }
    string attackMessage(BaseCharacter* opp) override {
        int message = rand() % 5;
        if (message == 0) return currentMessage = name + " bites " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 1) return currentMessage = "ERRRR. " + name + " bit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
        else if (message == 2) return currentMessage = name + " has fun chomping at " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 3) return currentMessage = "ERRRR. " + name + " wants " + opp->getName() + "'s brains" + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " wants some fresh meat. He attacks " + opp->getName() + damageMessage(opp->getLatestDamage());
    }
};

#endif
