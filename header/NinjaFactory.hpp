#ifndef __NINJA_FACTORY__
#define __NINJA_FACTORY__

#include "Ninja.hpp"
#include "AbstractPlayerFactory.hpp"

#include "AoeDecorator.hpp"
#include "DodgeDecorator.hpp"

class NinjaFactory : public AbstractPlayerFactory {
 private:
    string playerInfo;
    virtual Player* addDecorators(Player* p) {
        return new AoeDecorator(new DodgeDecorator(p));
    }
 public:
    NinjaFactory();
    virtual Player* getDefaultPlayer() const override {
        return addDecorators(new Ninja());
    }
    virtual Player* getUpgradedPlayer(const string &name, int xp) const override {

    }
};

#endif