#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
    virtual void attack(vector<BaseCharacter*> charList) {
        for (int i = charList.begin() + 1; i != charList.end(); ++i) {
            if (!(rand % 5)) {
                charList.at(i).defend();
            }
        }
    }
    virtual void defend(int damage) {return c->defend(damage)}
};

#endif