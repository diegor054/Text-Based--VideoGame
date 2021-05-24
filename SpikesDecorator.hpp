#ifndef __SPIKES_DECORATOR__
#define __SPIKES_DECORATOR__

class SpikesDecorator : public AbilityDecorator {
 public:
    SpikesDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {return c->attack(charList);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 3) {
            charList.at(attackerIndex).defend(attackStrength / 5);
        }
        return c->defend(damage);
    }
};

#endif