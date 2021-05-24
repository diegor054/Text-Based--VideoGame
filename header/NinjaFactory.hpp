#ifndef __NINJA_FACTORY__
#define __NINJA_FACTORY__

#include "Ninja.hpp"
#include "AbstractPlayerFactory.hpp"

class NinjaFactory : public AbstractPlayerFactory {
 private:
    string playerInfo;
 public:
    NinjaFactory();
    virtual Player* getDefaultPlayer() const override {
        return new Ninja();
    }
    virtual Player* getUpgradedPlayer(const string &name, int xp, int abilityData) const override {

    }
    virtual string getPlayerInfo() const override {

    }
};

#endif