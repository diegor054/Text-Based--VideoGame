#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include "BaseCharacter.hpp"

class Player : public BaseCharacter {
 protected:
    string weaponType;
    int playerLevel;
    int currentXP;
    string damageMessage(int damage) {
        int message = rand() % 2;
        if (message == 0) return ". They lost " + to_string(damage) + " health!"; 
        else if (message == 1) return " and dealt " + to_string(damage) + " damage!";
        else return ". They only have " + to_string(damage) + " health left."; 
    }
 public:
    Player() { }
    ~Player() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        int numOpponents = charList.size() - 1;
        int opponentIndex = rand() % numOpponents + 1;
        charList.at(opponentIndex)->defend(charList, attackerIndex, this->attackStrength);
        this->currentXP += charList.at(opponentIndex)->getLatestDamage();
        if (this->getOutputStatus()) cout << attackMessage(charList.at(opponentIndex)) << endl;
        return charList.at(opponentIndex);
    }
    virtual string attackMessage(BaseCharacter* opp) = 0;
    void setMaxHealth() { health = maxHealth; }
    int getLevel() override { return this->playerLevel; }
    void UpdateLevel() {
        xp += currentXP;
        currentXP = 0;
        playerLevel = 0.317 * pow(xp, 0.343);
        if (playerLevel < 0) playerLevel = 0;
        health = maxHealth = baseHealth * (1 + 0.1 * pow(playerLevel, 1.6));
        attackStrength = baseAttackStrength * (1 + 0.1 * pow(playerLevel, 1.6));
    }
    void refresh(bool keepXP) override {
        if (keepXP) UpdateLevel();
        this->latestDamage = 0;
        this->currentMessage = "";
        this->health = this->maxHealth;
    }
};

#endif
