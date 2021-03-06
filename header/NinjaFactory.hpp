#ifndef __NINJA_FACTORY__
#define __NINJA_FACTORY__

#include "Ninja.hpp"
#include "AbstractPlayerFactory.hpp"

#include "AoeDecorator.hpp"
#include "DodgeDecorator.hpp"

class NinjaFactory : public AbstractPlayerFactory {
 private:
    virtual BaseCharacter* addDecorators(Player* p) {
        return new AoeDecorator(new DodgeDecorator(p));
    }
 public:
    NinjaFactory() { playerInfo = "You are the Ninja. Your agility helps you to stealthily avoid some of the enemies attacks. You also have shurikens which can damage multiple opponents at once."; }
    virtual BaseCharacter* getDefaultPlayer() override {
        return addDecorators(new Ninja());
    }
    virtual BaseCharacter* getUpgradedPlayer(const string &name, int xp) override {
        Ninja* n = new Ninja();
        n->setName(name);
        n->setXP(xp);
        return addDecorators(n);
    }
    virtual string getPlayerInfo() override { return playerInfo; }
};

#endif
