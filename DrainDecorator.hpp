#ifndef __DRAIN_DECORATOR__
#define __DRAIN_DECORATOR__

class DrainDecorator : public AbilityDecorator {
 public:
    DrainDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        BaseCharacter* victim = c.attack(charList);
        c.setHealth(c.getHealth() + victim.latestDamage() / 5);
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return c->defend(damage);}
};

#endif