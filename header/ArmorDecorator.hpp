#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

#include "AbilityDecorator.hpp"

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    ~ArmorDecorator() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 2) {
            return character->defend(charList, attackerIndex, (damage * (0.0781 + sqrt(0.01036 * this->getLevel() + 0.0007668))/0.00518) / 100);
	    int rand = (rand() % 3) + 1;
	    if(rand == 1){
            addAbilityMessage(charList.at(attackerIndex)->getName() + " faced a wall of armor while trying to hurt " + this->character->getName());
	    }
            else if(rand == 2){
            addAbilityMessage(charList.at(attackerIndex)->getName() + "'s damage was reduced while trying to hurt " + this->character->getName());
            }else{
            addAbilityMessage(charList.at(attackerIndex)->getName() + " faced difficulty trying to hurt " + this->character->getName());
            }     
            cout << this->currentMessage << endl;
            this->currentMessage = "";
        }
        return character->defend(charList, attackerIndex, damage);
    }
};

#endif
