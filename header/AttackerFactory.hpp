#ifndef __ATTACKER_FACTORY__
#define __ATTACKER_FACTORY__

#include "Attacker.hpp"
#include "AbstractPlayerFactory.hpp"

class AttackerFactory : public AbstractPlayerFactory {
 private:
    string type = "Attacker";
 public:
    AttackerFactory();
    virtual Player* getDefaultPlayer() const override {return new Attacker();}
    virtual Player* getUpgradedPlayer(const string &name, const string &xp, const string &abilityData) const override {

    }
    virtual string getPlayerInfo() const override {

    }
};

#endif