#ifndef __SPIKES_DECORATOR__
#define __SPIKES_DECORATOR__

#include "AbilityDecorator.hpp"

class SpikesDecorator : public AbilityDecorator {
 public:
    SpikesDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 3) {
            charList.at(attackerIndex)->defend(charList, attackerIndex, attackStrength / 5);
        }
        return this->character->defend(charList, attackerIndex, damage);
    }
};

#endif
