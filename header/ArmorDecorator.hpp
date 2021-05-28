#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

#include "AbilityDecorator.hpp"

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        return character->defend(charList, attackerIndex, damage / 2);
    }
};

#endif