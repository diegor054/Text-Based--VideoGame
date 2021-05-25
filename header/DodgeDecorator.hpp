#ifndef __DODGE_DECORATOR__
#define __DODGE_DECORATOR__

#include "AbilityDecorator.hpp"

class DodgeDecorator : public AbilityDecorator {
 public:
    DodgeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {return this->character->attack(charList);}
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