#ifndef __RIGHT_PATH_FACTORY__
#define __RIGHT_PATH_FACTORY__

#include "AbstractStageFactory.hpp"

class RightPathFactory : public AbstractStageFactory {
 public:
    RightPathFactory(BaseCharacter* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() override {return vector<BaseCharacter*>{player, new Zombies(2)};}
    virtual vector<BaseCharacter*> getStage2() override {return vector<BaseCharacter*>{player, new Zombies(3), new Fairies(2)};}
    virtual vector<BaseCharacter*> getStage3() override {return vector<BaseCharacter*>{player, new Zombies(3), new Fairies(3), new Goblins(2)};}
    virtual vector<BaseCharacter*> getStage4() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombies(4)), new Zombies(4)};} 
    virtual vector<BaseCharacter*> getStage5() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombies(4)), new SpikesDecorator(new Zombies(4)), new DrainDecorator(new Fairies(3)), new DrainDecorator(new Fairies(3))};}
    virtual vector<BaseCharacter*> getStage6() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombies(5)), new SpikesDecorator(new Zombies(5)), new DrainDecorator(new Fairies(4)), new DrainDecorator(new Fairies(4)), new CriticalDecorator(new Goblins(4)), new CriticalDecorator(new Goblins(3))};}
    virtual vector<BaseCharacter*> getStage7() override {return vector<BaseCharacter*>{player, new SpikesDecorator(new Zombies(6)), new DrainDecorator(new Fairies(6)), new CriticalDecorator(new Goblins(6))};}
    virtual vector<BaseCharacter*> getStage8() override {return vector<BaseCharacter*>{player, new ArmorDecorator(new SpikesDecorator(new Zombies(7))), new CriticalDecorator(new ArmorDecorator(new SpikesDecorator(new Zombies(6)))), new DrainDecorator(new SpikesDecorator(new Fairies(7))), new CriticalDecorator(new DodgeDecorator(new Goblins(7))), new CriticalDecorator(new DodgeDecorator(new ArmorDecorator(new Goblins(3))))};}
    virtual vector<BaseCharacter*> getStage9() override {return vector<BaseCharacter*>{player, new Zombies(9), new Fairies(8), new Goblins(8), new CriticalDecorator(new ArmorDecorator(new Zombies(6))), new CriticalDecorator(new ArmorDecorator(new Zombies(6))), new DrainDecorator(new SpikesDecorator(new Fairies(6))), new DrainDecorator(new SpikesDecorator(new Fairies(6))), new CriticalDecorator(new DodgeDecorator(new Goblins(6))), new CriticalDecorator(new DodgeDecorator(new Goblins(6)))};}
    virtual vector<BaseCharacter*> getStage10() override {return vector<BaseCharacter*>{player, new CriticalDecorator(new DrainDecorator(new DodgeDecorator(new ArmorDecorator(new SpikesDecorator(new Goblins(10))))))};}
};

#endif
