#ifndef __CRITICAL_DECORATOR__
#define __CRITICAL_DECORATOR__

#include "AbilityDecorator.hpp"

class CriticalDecorator : public AbilityDecorator {
 public:
    CriticalDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        BaseCharacter* victim = this->character->attack(charList);
        victim->defend(charList, 99, attackStrength / 2); //fixme 99
        return victim;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return this->character->defend(charList, attackerIndex, damage);}
};

#endif
