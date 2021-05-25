#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

#include "AbilityDecorator.hpp"

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        this->character->attack(charList);
        for (vector<BaseCharacter*>::iterator i = charList.begin() + 1; i != charList.end(); ++i) {
            if (!(rand() % 5)) {
                charList.at(i).defend(this->character->attackStrength / 3);
            }
        }
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return c->defend(damage);}
};

#endif