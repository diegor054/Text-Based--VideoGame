#ifndef __DRAIN_DECORATOR__
#define __DRAIN_DECORATOR__

#include "AbilityDecorator.hpp"

class DrainDecorator : public AbilityDecorator {
 public:
    DrainDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        BaseCharacter* victim = this->character->attack(charList, attackerIndex);
        if (!(rand() % 3)) {
            this->character->setHealth(character->getHealth() + (victim->getLatestDamage() * (0.181 + 0.0514 * this->getLevel() + 2.59 * pow(10, -3) * pow(this->getLevel(), 2) + 25)) / 100);
            addAbilityMessage(this->character->getName() + " managed to gain " + to_string((victim->getLatestDamage() * (0.181 + 0.0514 * this->getLevel() + 2.59 * pow(10, -3) * pow(this->getLevel(), 2) + 25)) / 100) + " from " + victim->getName());
            cout << this->currentMessage << endl;
            this->currentMessage = "";
            return victim;
        }
        return victim;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return this->character->defend(charList, attackerIndex, damage);}
};

#endif
