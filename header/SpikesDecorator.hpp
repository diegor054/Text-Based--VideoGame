#ifndef __SPIKES_DECORATOR__
#define __SPIKES_DECORATOR__

class SpikesDecorator : public AbilityDecorator {
 public:
    SpikesDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {return this->character->attack(charList);}
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {
        if (rand() % 3) {
            charList.at(attackerIndex)->defend(charList, attackerIndex, attackStrength / 5);
        }
        return this->character->defend(charList, attackerIndex, damage);
    }
};

#endif