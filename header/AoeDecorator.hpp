#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

#include "AbilityDecorator.hpp"

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    ~AoeDecorator() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        BaseCharacter* opp = this->character->attack(charList, attackerIndex);
        for (vector<BaseCharacter*>::iterator it = charList.begin() + 1; it != charList.end(); ++it) {
            if ((rand() % 100 + 1) <= ((0.0236 + sqrt(0.02512 * this->getLevel() + 0.00573168))/0.01256) && (*it) != opp) {
                (*it)->defend(charList, 0, this->character->getAttackStrength() / 3);
                int r = (rand() % 3) + 1;
                if(r == 1){
                addAbilityMessage(this->character->getName() + " managed to also hit " + (*it)->getName() + " and deal " + to_string((*it)->getLatestDamage()) + " damage.");
                }else if(r == 2){
                addAbilityMessage(this->character->getName() + " managed attack " + (*it)->getName() + " and deal " + to_string((*it)->getLatestDamage()) + " damage too."); 
               }else{
                addAbilityMessage(this->character->getName() + " also hit " + (*it)->getName() + " and dealt " + to_string((*it)->getLatestDamage()) + " damage.");
               }
                cout << this->currentMessage << endl;
                this->currentMessage = "";
            }
        }
        return opp;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return character->defend(charList, attackerIndex, damage);}
};

#endif
