#ifndef __DODGE_DECORATOR__
#define __DODGE_DECORATOR__

#include "AbilityDecorator.hpp"

class DodgeDecorator : public AbilityDecorator {
 public:
    DodgeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {return c->attack(charList);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (!(rand() % 2)) {
            if (!(rand() % 2)) {
                return c->defend(0);
            }
            else {
                return c->defend(damage/2);
            }
        }
    }
};

#endif