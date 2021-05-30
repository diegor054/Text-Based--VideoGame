#ifndef __ZOMBIES_HPP__
#define __ZOMBIES_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Zombies : public Opponent {
 private:
    
 public:
    Zombies() {
        name = characterType = "Zombie"; 
        health = maxHealth = baseHealth = 25;
        attackStrength = baseAttackStrength = 5;
        xp = opponentLevel = 0;
        refresh(false);
        attackStyle = "Teeth";
    }
    string attackMessage(BaseCharacter* opp) override {
        int message = rand() % 3;
        if (message == 0) return currentMessage = name + " bites " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 1) return currentMessage = "ERRRR. " + name + " bit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " wants some fresh meat. He attacks " + opp->getName() + damageMessage(opp->getLatestDamage());
    }
};

#endif
