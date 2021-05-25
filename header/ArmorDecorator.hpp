#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

#include "AbilityDecorator.hpp"

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {return this->character->attack(charList);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        return character->defend(charList, attackerIndex, damage / 2);
    }
};

#endif