#ifndef __DODGE_DECORATOR__
#define __DODGE_DECORATOR__

#include "AbilityDecorator.hpp"

class DodgeDecorator : public AbilityDecorator {
 public:
    DodgeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    ~DodgeDecorator() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if ((rand() % 100 + 1) <= (0.15038 + sqrt(0.01524 * this->getLevel() + 0.00015648))/0.00762) {
            if (!(rand() % 3)) {
                charList.at(attackerIndex)->setOutputStatus(false);
                int dmg = this->character->defend(charList, attackerIndex, 0);
                int r = (rand() % 3) + 1;
                if(r == 1){
                addAbilityMessage(charList.at(attackerIndex)->getName() + " slipped on a banana while trying to hurt " + this->character->getName());
                } else if(r == 2){
                addAbilityMessage(charList.at(attackerIndex)->getName() + " completely missed while trying to hurt " + this->character->getName());
                } else{
                addAbilityMessage(charList.at(attackerIndex)->getName() + " missed and could not hurt " + this->character->getName());
                }
                cout << this->currentMessage << endl;
                this->currentMessage = "";
                return dmg;
            }
            else {
                int dmg = this->character->defend(charList, attackerIndex, damage / 2);
                int r2 = (rand() % 3) + 1;
                if(r2 == 1){
                addAbilityMessage(charList.at(attackerIndex)->getName() + " slipped on a puddle and barely scraped " + this->character->getName());
                }else if(r2 == 2){
                addAbilityMessage(charList.at(attackerIndex)->getName() + " tripped and could only do half damage " + this->character->getName());
                }else{
                addAbilityMessage(charList.at(attackerIndex)->getName() + " could only do half damage due to a dodge by  " + this->character->getName());
                }
                cout << this->currentMessage << endl;
                this->currentMessage = "";
                return dmg;
            }
        }
        else return this->character->defend(charList, attackerIndex, damage);
    }
};

#endif
