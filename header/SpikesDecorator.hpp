#ifndef __SPIKES_DECORATOR__
#define __SPIKES_DECORATOR__

#include "AbilityDecorator.hpp"

class SpikesDecorator : public AbilityDecorator {
 public:
    SpikesDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    ~SpikesDecorator() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {return this->character->attack(charList, attackerIndex);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 2) {
            charList.at(attackerIndex)->defend(charList, attackerIndex, (this->getAttackStrength() * (0.0236 + sqrt(0.02512 * this->getLevel() + 0.00573168)) / 0.01256) / 100);
            int r = (rand() % 3);
            if (r == 0) addAbilityMessage(charList.at(attackerIndex)->getName() + " was thorned for " + to_string(static_cast<int>((this->getAttackStrength() * 0.186 + 0.102 * this->getLevel() + 6.28 * pow(10, -3) * pow(this->getLevel(), 2) + 10) / 100)) + " damage whilst trying to hurt " + this->character->getName());
            else if (r == 1) addAbilityMessage(charList.at(attackerIndex)->getName() + " took " + to_string(static_cast<int>((this->getAttackStrength() * 0.186 + 0.102 * this->getLevel() + 6.28 * pow(10, -3) * pow(this->getLevel(), 2) + 10) / 100)) + " damage whilst trying to hurt " + this->character->getName());
            else addAbilityMessage(charList.at(attackerIndex)->getName() + " was spiked for " + to_string(static_cast<int>((this->getAttackStrength() * 0.186 + 0.102 * this->getLevel() + 6.28 * pow(10, -3) * pow(this->getLevel(), 2) + 10) / 100)) + " damage whilst trying to hurt " + this->character->getName());
            cout << this->currentMessage << endl;
            this->currentMessage = "";
        }
        return this->character->defend(charList, attackerIndex, damage);
    }
};

#endif
