#ifndef __ARMOR_DECORATOR__
#define __ARMOR_DECORATOR__

class ArmorDecorator : public AbilityDecorator {
 public:
    ArmorDecorator(BaseCharacter* c) : AbilityDecorator(c) { }
};

#endif