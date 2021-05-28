#ifndef __ABILITY_DECORATOR__
#define __ABILITY_DECORATOR__

#include "BaseCharacter.hpp"

class AbilityDecorator : public BaseCharacter {
 protected:
    BaseCharacter* character;
 public:
    AbilityDecorator(BaseCharacter* c) : BaseCharacter(), character(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
    string attackMessage(BaseCharacter* opp) override { return this->character->attackMessage(opp); }
    void addAbilityMessage(const string &newMessage) {
        if (currentMessage != "") currentMessage += "\n" + newMessage;
        else currentMessage = newMessage;
    }
};

#endif