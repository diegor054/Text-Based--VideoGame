#ifndef __ABILITY_DECORATOR__
#define __ABILITY_DECORATOR__

#include "BaseCharacter.hpp"

class AbilityDecorator : public BaseCharacter {
 protected:
    BaseCharacter* character;
 public:
    AbilityDecorator(BaseCharacter* c) : BaseCharacter(), character(c) { }
    virtual void attack(vector<BaseCharacter*>) = 0;
    virtual void defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
};

#endif