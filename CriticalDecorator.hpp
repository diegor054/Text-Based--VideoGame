#ifndef __CRITICAL_DECORATOR__
#define __CRITICAL_DECORATOR__

class CriticalDecorator : public AbilityDecorator {
 public:
    CriticalDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        BaseCharacter* victim = c.attack(charList);
        victim.defend(attackStrength / 2);
        return victim;
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return c->defend(damage);}
};

#endif