#ifndef __GOBLIN_HPP__
#define __GOBLIN_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Goblin : public Opponent {
 private:

 public:
    Goblin() {
        name = characterType = "Goblin";
        health = maxHealth = baseHealth = 50;
        attackStrength = baseAttackStrength = 2;
        xp = opponentLevel = 0;
        refresh(false);
        attackStyle = "Knife";
    }
    Goblin(int level) {
        name = characterType = "Goblin";
        baseHealth = 50;
        baseAttackStrength = 2;
        xp = opponentLevel = level;
        health = maxHealth = baseHealth * (1 + 0.1 * pow(opponentLevel, 1.6));
        attackStrength = baseAttackStrength * (1 + 0.1 * pow(opponentLevel, 1.6));
        refresh(false);
        attackStyle = "Knife";
    }
    string attackMessage(BaseCharacter* opp) override {
        int message = rand() % 5;
        if (message == 0) return currentMessage = name + " knife " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 1) return currentMessage = name + " hit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
        else if (message == 2) return currentMessage = name + " wasted no time with " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 3) return currentMessage = name + " smashed " + opp->getName() + " with great force" + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " is very mad at you and attacked " + opp->getName() + damageMessage(opp->getLatestDamage());
    }
};

#endif
