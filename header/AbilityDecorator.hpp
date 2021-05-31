#ifndef __ABILITY_DECORATOR__
#define __ABILITY_DECORATOR__

#include "BaseCharacter.hpp"

class AbilityDecorator : public BaseCharacter {
 protected:
    BaseCharacter* character;
 public:
    AbilityDecorator(BaseCharacter* c) : BaseCharacter(), character(c) { 
        name = "dec_name";
        characterType = "dec_type";
        health = maxHealth = baseHealth = attackStrength = baseAttackStrength = xp = latestDamage = 0;
        currentMessage = "dec_null";
        outputMessages = true;
    }
    ~AbilityDecorator() override { delete this->character; }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) = 0;
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) = 0;
    string attackMessage(BaseCharacter* opp) override { return this->character->attackMessage(opp) + "\n" + this->currentMessage; }
    string getHealthBar() const override { return this->character->getHealthBar(); }
    void setName(string n) override { return this->character->setName(n); }
    void setType(string t) override { return this->character->setType(t); }
    void setHealth(int h) override { return this->character->setHealth(h); }
    void setXP(int x) override { return this->character->setXP(x); }
    void setOutputStatus(bool o) override { return this->character->setOutputStatus(o); }
    void setAttackStrength(int a) override { return this->character->setAttackStrength(a); }
    string getName() override { return this->character->getName(); }
    string getType() override { return this->character->getType(); }
    int getHealth() override { return this->character->getHealth(); }
    int getXP() override { return this->character->getXP(); }
    bool getOutputStatus() override { return this->character->getOutputStatus(); }
    int getLatestDamage() override { return this->character->getLatestDamage(); }
    int getAttackStrength() override { return this->character->getAttackStrength(); }
    int getLevel() override { return this->character->getLevel(); }
    void addAbilityMessage(const string &newMessage) {
        if (currentMessage != "") currentMessage += "\n" + newMessage;
        else currentMessage = newMessage;
    }
    void refresh(bool keepXP) override {
        return this->character->refresh(keepXP);
    }
};

#endif
