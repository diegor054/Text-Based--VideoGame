#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

#include "AbilityDecorator.hpp"

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        addAbilityMessage(charList.at(attackerIndex)->getName() + " faced a wall of armor while trying to hurt " + this->character->getName());
        cout << this->currentMessage << endl;
        this->currentMessage = "";
        return character->defend(charList, attackerIndex, damage / 2);
    }
};

#endif