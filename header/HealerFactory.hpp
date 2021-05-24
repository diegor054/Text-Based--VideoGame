#ifndef __HEALER_FACTORY__
#define __HEALER_FACTORY__

#include "Healer.hpp"
#include "AbstractPlayerFactory.hpp"

class HealerFactory : public AbstractPlayerFactory {
 private:
    string playerInfo;
 public:
    HealerFactory();
    virtual Player* getDefaultPlayer() const override {
        return new Healer();
    }
    virtual Player* getUpgradedPlayer(const string &name, int xp, int abilityData) const override {

    }
    virtual string getPlayerInfo() const override {

    }
};

#endif