#ifndef __HEALER_FACTORY__
#define __HEALER_FACTORY__

#include "Healer.hpp"
#include "AbstractPlayerFactory.hpp"

#include "DrainDecorator.hpp"
#include "SpikesDecorator.hpp"

class HealerFactory : public AbstractPlayerFactory {
 private:
    virtual BaseCharacter* addDecorators(Player* p) {
        return new DrainDecorator(new SpikesDecorator(p));
    }
 public:
    HealerFactory() { playerInfo = "You are the Healer. Your magical abilities allow you to drain the opponent of their health while healing yours. You also have spikes which will damage the opponent when they attack you."; }
    virtual BaseCharacter* getDefaultPlayer() override {
        return addDecorators(new Healer());
    }
    virtual BaseCharacter* getUpgradedPlayer(const string &name, int xp) override {
        Healer* h = new Healer();
        h->setName(name);
        h->setXP(xp);
        return addDecorators(h);
    }
    virtual string getPlayerInfo()override{ return playerInfo; }

};

#endif
