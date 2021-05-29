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
    }
 public:
    Player() { }
    ~Player() = default;
    BaseCharacter* attack(vector<BaseCharacter*> charList, int attackerIndex) override {
        int numOpponents = charList.size() - 1;
        int opponentIndex = rand() % numOpponents + 1;
        charList.at(opponentIndex)->defend(charList, attackerIndex, this->attackStrength);
        this->currentXP += charList.at(opponentIndex)->getLatestDamage();
        cout << attackMessage(charList.at(opponentIndex)) << endl;
        return charList.at(attackerIndex);
    }
    int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) override { 
        if (health - damage > 0) {
            this->setHealth(health - damage);
            return latestDamage = damage;
        }
        else {
            latestDamage = health;
            this->setHealth(0);
            return latestDamage;
        }
    }
    virtual string attackMessage(BaseCharacter* opp) = 0;
    void setMaxHealth() { health = maxHealth; }
    void UpdateLevel() {
        xp += currentXP;
        currentXP = 0;
        playerLevel = -3.01 + 0.867 * log(xp); //L0 = 0, L1 = 100, L2 = 333, L3 = 1000, L4 = 3333 ...
        if (playerLevel < 0) playerLevel = 0;
    }
    void refresh(bool keepXP) override {
        if (keepXP) UpdateLevel();
        this->latestDamage = 0;
        this->currentMessage = "";
        this->health = this->maxHealth;
    }
};

#endif
