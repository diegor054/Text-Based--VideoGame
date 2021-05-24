#ifndef __ATTACKER_FACTORY__
#define __ATTACKER_FACTORY__

#include "Attacker.hpp"
#include "AbstractPlayerFactory.hpp"

#include "CriticalDecorator.hpp"
#include "ArmorDecorator.hpp"

class AttackerFactory : public AbstractPlayerFactory {
 private:
    string playerInfo = "You are the Attacker. You are strong, and have the chance to deal extra damage on the opponent. You also have armor which will protect you from your opponents.";
    virtual Player* addDecorators(Player* p) {
        return new CriticalDecorator(new ArmorDecorator(p));
    }
 public:
    AttackerFactory();
    virtual Player* getDefaultPlayer() const override {
        return addDecorators(new Attacker());
    }
    virtual Player* getUpgradedPlayer(const string &name, int xp) const override {
        Attacker* a = new Healer();
        a->setName(name);
        a->setXP(xp);
        return addDecorators(a);
    }
};

#endif