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
                addAbilityMessage(charList.at(attackerIndex)->getName() + " slipped on a banana while trying to hurt " + this->character->getName());
                cout << this->currentMessage << endl;
                this->currentMessage = "";
                return this->character->defend(charList, attackerIndex, 0);
            }
            else {
                addAbilityMessage(charList.at(attackerIndex)->getName() + " slipped on a puddle while trying to hurt " + this->character->getName());
                cout << this->currentMessage << endl;
                this->currentMessage = "";
                return this->character->defend(charList, attackerIndex, damage / 2);
            }
        }
        else return this->character->defend(charList, attackerIndex, damage);
    }
};

#endif