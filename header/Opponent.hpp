#ifndef __OPPONENT_HPP__
#define __OPPONENT_HPP__

#include "BaseCharacter.hpp"

class Opponent : public BaseCharacter {
 protected:
    int opponentLevel;
    string attackStyle;
    string damageMessage(int damage) {
        int message = rand() % 4;
        if (message == 0) return " and took off " + to_string(damage) + " damage!";
        else if (message == 1) return ". You lost " + to_string(damage) + " health!"; 
        else if (message == 2) return ". He attacked you for " + to_string(damage) + " health!";
        else if (message == 3) return " and deals " + to_string(damage) + " damage!";
        else return " and attacked you for " + to_string(damage) + " health!";
    }
 public:
    Opponent() { }
    ~Opponent() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        int opponentIndex = 0;
        charList.at(opponentIndex)->defend(charList, attackerIndex, this->attackStrength);
        if (this->getOutputStatus()) cout << attackMessage(charList.at(opponentIndex)) << endl;
        this->setOutputStatus(true);
        return charList.at(opponentIndex);
    }
    int getLevel() override { return this->opponentLevel; }
    void refresh(bool keepXP) override {
        this->latestDamage = 0;
        this->currentMessage = "";
        this->health = this->maxHealth;
    }
};

#endif
