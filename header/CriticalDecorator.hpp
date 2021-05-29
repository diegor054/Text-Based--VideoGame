#ifndef __CRITICAL_DECORATOR__
#define __CRITICAL_DECORATOR__

#include "AbilityDecorator.hpp"

class CriticalDecorator : public AbilityDecorator {
 public:
    CriticalDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        int temp = getAttackStrength();
        if (rand() % 2) {
            setAttackStrength(temp * 1.5);
        }
        BaseCharacter* victim = this->character->attack(charList, attackerIndex);
        addAbilityMessage(this->character->getName() + " critically hit " + victim->getName() + "!");
        cout << this->currentMessage << endl;
        this->currentMessage = "";
        setAttackStrength(temp);
        return victim;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return this->character->defend(charList, attackerIndex, damage);}
};

#endif
