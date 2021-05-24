#ifndef __SPIKES_DECORATOR__
#define __SPIKES_DECORATOR__

class SpikesDecorator : public AbilityDecorator {
 public:
    SpikesDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
};

#endif