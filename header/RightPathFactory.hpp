#ifndef __RIGHT_PATH_FACTORY__
#define __RIGHT_PATH_FACTORY__

#include "AbstractStageFactory.hpp"

class RightPathFactory : public AbstractStageFactory {
 public:
    RightPathFactory(BaseCharacter* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins()};} // see green moving creature to the right which is why this is goblins
    virtual vector<BaseCharacter*> getStage2() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins()};}  //doubled
    virtual vector<BaseCharacter*> getStage3() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins()};} //these will be very strong
    virtual vector<BaseCharacter*> getStage4() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies()};} //time to choose again, they chose right since they were seeing sparkling dust 
    virtual vector<BaseCharacter*> getStage5() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies()};}
    virtual vector<BaseCharacter*> getStage6() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies()};}  // these will be very strong
    virtual vector<BaseCharacter*> getStage7() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies(), new Zombies()};} //hear loud growling and thumping so they went right
    virtual vector<BaseCharacter*> getStage8() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies(), new Zombies(), new Zombies(), new Zombies(), new Zombies()};} //increased to 7
    virtual vector<BaseCharacter*> getStage9() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies(), new Zombies()};} //these will be very strong
    virtual vector<BaseCharacter*> getStage10() override {return vector<BaseCharacter*>{player, new Goblins()};} //final boss, however we make it
};

#endif
