#ifndef __AOE_DECORATOR__
#define __AOE_DECORATOR__

class AoeDecorator : public AbilityDecorator {
 public:
    AoeDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
};

#endif