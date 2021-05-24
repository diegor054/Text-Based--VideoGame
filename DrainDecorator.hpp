#ifndef __DRAIN_DECORATOR__
#define __DRAIN_DECORATOR__

class DrainDecorator : public AbilityDecorator {
 public:
    DrainDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
};

#endif