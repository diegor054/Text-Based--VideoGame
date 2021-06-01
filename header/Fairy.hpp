#ifndef __FAIRY_HPP__
#define __FAIRY_HPP__

#include <iostream>
#include <cstdlib>

#include "Opponent.hpp"

class Fairy: public Opponent {
 private:

 public:
    Fairy() {
        name = characterType = "Fairy";
        health = maxHealth = baseHealth = 50;
        attackStrength = baseAttackStrength = 3;
        xp = opponentLevel = 0;
        refresh(false);
        attackStyle = "Pixie dust";
    }
    Fairy(int level) {
        name = characterType = "Fairy";
        baseHealth = 50;
        baseAttackStrength = 3;
        xp = opponentLevel = level;
        health = maxHealth = baseHealth * (1 + 0.1 * pow(opponentLevel, 1.6));
        attackStrength = baseAttackStrength * (1 + 0.1 * pow(opponentLevel, 1.6));
        refresh(false);
        attackStyle = "Pixie dust";
    }
    string attackMessage(BaseCharacter* opp) override {
        int message = rand() % 5;
        if (message == 0) return currentMessage = name + " sprinkles " + opp->getName() + damageMessage(opp->getLatestDamage());
        else if (message == 1) return currentMessage = name + " hit " + opp->getName() + " hard" + damageMessage(opp->getLatestDamage());
        else if (message == 2) return currentMessage = name + " strikes " + opp->getName() + " with a beam of light" + damageMessage(opp->getLatestDamage());
        else if (message == 3) return currentMessage = name + " uses magical powers against " + opp->getName() + damageMessage(opp->getLatestDamage());
        else return currentMessage = name + " is very mad at you and sprinkled " + opp->getName() + damageMessage(opp->getLatestDamage());
    }
};

#endif
