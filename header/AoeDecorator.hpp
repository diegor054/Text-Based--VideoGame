#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

#include "AbilityDecorator.hpp"

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        this->character->attack(charList);
        for (vector<BaseCharacter*>::iterator it = charList.begin() + 1; it != charList.end(); ++it) {
            if (!(rand() % 5)) {
                (*it)->defend(charList, 0, this->character->getAttackStrength() / 3);
            }
        }
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return character->defend(charList, attackerIndex, damage);}
};

#endif