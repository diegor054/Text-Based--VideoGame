#ifndef __HEALER_FACTORY__
#define __HEALER_FACTORY__

#include "Healer.hpp"
#include "AbstractPlayerFactory.hpp"

#include "DrainDecorator.hpp"
#include "SpikesDecorator.hpp"

class HealerFactory : public AbstractPlayerFactory {
 private:
    string playerInfo;
    virtual Player* addDecorators(Player* p) {
        return new DrainDecorator(new SpikesDecorator(p));
    }
 public:
    HealerFactory();
    virtual Player* getDefaultPlayer() const override {
        return addDecorators(new Healer());
    }
    virtual Player* getUpgradedPlayer(const string &name, int xp) const override {
        Healer* h = new Healer();
        h->setName(name);
        h->setXP(xp);
        return addDecorators(h);
    }
};

#endif