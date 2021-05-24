#ifndef __ABILITY_DECORATOR__
#define __ABILITY_DECORATOR__

#include "BaseCharacter.hpp"

class AbilityDecorator : public BaseCharacter {
 protected:
    BaseCharacter* character;
 public:
    AbilityDecorator(BaseCharacter* c) : BaseCharacter(), character(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*>) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
};

#endif