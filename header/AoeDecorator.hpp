#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual BaseCharacter* attack(vector<BaseCharacter*> charList) {
        c.attack(charList);
        for (int i = charList.begin() + 1; i != charList.end(); ++i) {
            if (!(rand % 5)) {
                charList.at(i).defend(c.attackStrength / 3);
            }
        }
    }
    virtual int defend(vector<BaseCharacter*> charList, int attackerIndex, int damage) {return c->defend(damage);}
};

#endif