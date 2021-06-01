#ifndef __CRITICAL_DECORATOR__
#define __CRITICAL_DECORATOR__

#include "AbilityDecorator.hpp"

class CriticalDecorator : public AbilityDecorator {
 public:
    CriticalDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    ~CriticalDecorator() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        if ((rand() % 100 + 1) <= ((0.1492 + sqrt(0.02512 * this->getLevel() + 0.00573168))/0.01256)) {
            int temp = getAttackStrength();
            setAttackStrength(temp * 1.5);
            BaseCharacter* victim = this->character->attack(charList, attackerIndex);
            int r = (rand() % 3) + 1;
            if(r == 1){
            addAbilityMessage(this->character->getName() + " critically hit " + victim->getName() + "!");
            }
            else if(r == 2){
            addAbilityMessage(this->character->getName() + " did extra damage to  " + victim->getName() + "!");
            }else{
            addAbilityMessage(this->character->getName() + "'s attack hit " + victim->getName() + " hard!");
            }  
            cout << this->currentMessage << endl;
            this->currentMessage = "";
            setAttackStrength(temp);
	    return victim;

        }
        return this->character->attack(charList, attackerIndex);
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return this->character->defend(charList, attackerIndex, damage);}
};

#endif
