#ifndef __ATTACKER_FACTORY__
#define __ATTACKER_FACTORY__

#include "Attacker.hpp"
#include "AbstractPlayerFactory.hpp"

#include "CriticalDecorator.hpp"
#include "ArmorDecorator.hpp"

class AttackerFactory : public AbstractPlayerFactory {
 private:
    string playerInfo = "You are the Attacker. You are strong, and have the chance to deal extra damage on the opponent. You also have armor which will protect you from your opponents.";
    virtual BaseCharacter* addDecorators(Player* p) {
        return new CriticalDecorator(new ArmorDecorator(p));
    }
 public:
    AttackerFactory() { };
    virtual BaseCharacter* getDefaultPlayer() override {
        return addDecorators(new Attacker());
    }
    virtual BaseCharacter* getUpgradedPlayer(const string &name, int xp) override {
        Attacker* a = new Attacker();
        a->setName(name);
        a->setXP(xp);
        return addDecorators(a);
    }
     virtual string getPlayerInfo()override{ return playerInfo; }
};

#endif
