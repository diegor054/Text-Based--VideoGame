#ifndef __GOBLINS_HPP__
#define __GOBLINS_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Goblins : public Opponent {
 private:

 public:
    Goblins() {
        name = characterType = "Goblin";
        health = maxHealth = baseHealth = 50;
        attackStrength = baseAttackStrength = 2;
        xp = opponentLevel = 0;
        refresh(false);
        attackStyle = "Knife";
    }
    string attackMessage(BaseCharacter* opp) override {
        int message = rand() % 3;
        if (message == 0) return currentMessage = name + " knife " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 1) return currentMessage = name + " hit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " is very mad at you and attacked " + opp->getName() + damageMessage(opp->getLatestDamage());
    }
};

#endif
