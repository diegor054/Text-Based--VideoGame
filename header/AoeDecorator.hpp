#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

#include "AbilityDecorator.hpp"

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        BaseCharacter* opp = this->character->attack(charList, attackerIndex);
        for (vector<BaseCharacter*>::iterator it = charList.begin() + 1; it != charList.end(); ++it) {
            if ((rand() % 100 + 1) <= (0.186 + 0.102 * this->getLevel() + 6.28 * pow(10, -3) * pow(this->getLevel(), 2) + 10) && (*it) != opp) {
                (*it)->defend(charList, 0, this->character->getAttackStrength() / 3);
                addAbilityMessage(this->character->getName() + " managed to also hit " + (*it)->getName() + " and deal " + to_string((*it)->getLatestDamage()) + " damage.");
                cout << this->currentMessage << endl;
                this->currentMessage = "";
            }
        }
        return opp;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return character->defend(charList, attackerIndex, damage);}
};

#endif