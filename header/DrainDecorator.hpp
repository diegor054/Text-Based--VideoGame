#ifndef __DRAIN_DECORATOR__
#define __DRAIN_DECORATOR__

#include "AbilityDecorator.hpp"

class DrainDecorator : public AbilityDecorator {
 public:
    DrainDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        BaseCharacter* victim = this->character->attack(charList);
        this->character->setHealth(character->getHealth() + victim->getLatestDamage() / 5);
        return victim;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return this->character->defend(charList, attackerIndex, damage);}
};

#endif
