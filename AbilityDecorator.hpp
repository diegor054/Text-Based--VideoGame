#ifndef __ABILITY_DECORATOR__
#define __ABILITY_DECORATOR__

#include "BaseCharacter.hpp"

class AbilityDecorator : public BaseCharacter {
 protected:
    BaseCharacter* character;
 public:
    AbilityDecorator(BaseCharacter* c) : BaseCharacter(), character(c) { }
    virtual void attack(vector<BaseCharacter*>) = 0;
    virtual void defend(int) = 0;
};

#endif