#ifndef __RIGHT_PATH_FACTORY__
#define __RIGHT_PATH_FACTORY__

#include "AbstractStageFactory.hpp"

class RightPathFactory : public AbstractStageFactory {
 public:
    RightPathFactory(BaseCharacter* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() override {return vector<BaseCharacter*>{player, new Zombie(2)};}
    virtual vector<BaseCharacter*> getStage2() override {return vector<BaseCharacter*>{player, new Zombie(3), new Fairy(2)};}
    virtual vector<BaseCharacter*> getStage3() override {return vector<BaseCharacter*>{player, new Zombie(3), new Fairy(3), new Goblin(2)};}
    virtual vector<BaseCharacter*> getStage4() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombie(4)), new Zombie(4)};} 
    virtual vector<BaseCharacter*> getStage5() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombie(4)), new SpikesDecorator(new Zombie(4)), new DrainDecorator(new Fairy(3)), new DrainDecorator(new Fairy(3))};}
    virtual vector<BaseCharacter*> getStage6() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombie(5)), new SpikesDecorator(new Zombie(5)), new DrainDecorator(new Fairy(4)), new DrainDecorator(new Fairy(4)), new CriticalDecorator(new Goblin(4)), new CriticalDecorator(new Goblin(3))};}
    virtual vector<BaseCharacter*> getStage7() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombie(6)), new DrainDecorator(new Fairy(6)), new CriticalDecorator(new Goblin(6))};}
    virtual vector<BaseCharacter*> getStage8() override {return vector<BaseCharacter*>{player, new ArmorDecorator(new SpikesDecorator(new Zombie(7))), new CriticalDecorator(new ArmorDecorator(new SpikesDecorator(new Zombie(6)))), new DrainDecorator(new SpikesDecorator(new Fairy(7))), new CriticalDecorator(new DodgeDecorator(new Goblin(7))), new CriticalDecorator(new DodgeDecorator(new ArmorDecorator(new Goblin(3))))};}
    virtual vector<BaseCharacter*> getStage9() override {return vector<BaseCharacter*>{player, new Zombie(9), new Fairy(8), new Goblin(8), new CriticalDecorator(new ArmorDecorator(new Zombie(6))), new CriticalDecorator(new ArmorDecorator(new Zombie(6))), new DrainDecorator(new SpikesDecorator(new Fairy(6))), new DrainDecorator(new SpikesDecorator(new Fairy(6))), new CriticalDecorator(new DodgeDecorator(new Goblin(6))), new CriticalDecorator(new DodgeDecorator(new Goblin(6)))};}
    virtual vector<BaseCharacter*> getStage10() override {return vector<BaseCharacter*>{player, new CriticalDecorator(new DrainDecorator(new DodgeDecorator(new ArmorDecorator(new SpikesDecorator(new Goblin(10))))))};}
};

#endif
