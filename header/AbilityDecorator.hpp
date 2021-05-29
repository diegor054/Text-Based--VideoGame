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
    void setName(string n) override { return this->character->setName(n); }
    void setType(string t) override { return this->character->setType(t); }
    void setHealth(int h) override { return this->character->setHealth(h); }
    void setXP(int x) override { return this->character->setXP(x); }
    string getName() override { return this->character->getName(); }
    string getType() override { return this->character->getType(); }
    int getHealth() override { return this->character->getHealth(); }
    int getXP() override { return this->character->getXP(); }
    int getLatestDamage() override { return this->character->getLatestDamage(); }
    int getAttackStrength() override { return this->character->getAttackStrength(); }
    void addAbilityMessage(const string &newMessage) {
        if (currentMessage != "") currentMessage += "\n" + newMessage;
        else currentMessage = newMessage;
    }
    void refresh(bool keepXP) override {
        return this->character->refresh(keepXP);
    }
};

#endif
