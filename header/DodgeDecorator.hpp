#ifndef __DODGE_DECORATOR__
#define __DODGE_DECORATOR__

#include "AbilityDecorator.hpp"

class DodgeDecorator : public AbilityDecorator {
 public:
    DodgeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (!(rand() % 2)) {
            if (!(rand() % 2)) {
                return this->character->defend(charList, attackerIndex, 0);
            }
            else {
                return this->character->defend(charList, attackerIndex, damage/2);
            }
        }
    }
};

#endif