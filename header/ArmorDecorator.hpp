#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

#include "AbilityDecorator.hpp"

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 2) {
            addAbilityMessage(charList.at(attackerIndex)->getName() + " faced a wall of armor while trying to hurt " + this->character->getName());
            cout << this->currentMessage << endl;
            this->currentMessage = "";
            return character->defend(charList, attackerIndex, (damage * (0.181 + 0.0514 * this->getLevel() + 2.59 * pow(10, -3) * pow(this->getLevel(), 2) + 25)) / 100);
        }
        return character->defend(charList, attackerIndex, damage);
    }
};

#endif