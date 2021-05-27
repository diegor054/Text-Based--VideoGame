#ifndef __LEFT_PATH_FACTORY__
#define __LEFT_PATH_FACTORY__

#include "AbstractStageFactory.hpp"

class LeftPathFactory : public AbstractStageFactory {
 public:
    LeftPathFactory(BaseCharacter* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies()};} //we hear growling
    virtual vector<BaseCharacter*> getStage2() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies(), new Zombies(), new Zombies()};}  //increasing it
    virtual vector<BaseCharacter*> getStage3() override {return vector<BaseCharacter*>{player, new Zombies(), new Zombies(), new Zombies(), new Zombies(), new Zombies()};} // these will be leveled up
    //this is where player chooses path again. can say something like (we see a green creature in the distance. would you like to go to the left and apporach it)
    virtual vector<BaseCharacter*> getStage4() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins(), new Goblins()};}
    virtual vector<BaseCharacter*> getStage5() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins()};} //double goblins
    virtual vector<BaseCharacter*> getStage6() override {return vector<BaseCharacter*>{player, new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins(), new Goblins()};} //upgraded goblins  
     // you see fairy dust to the left and are amused by it
    virtual vector<BaseCharacter*> getStage7() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies()};}
    virtual vector<BaseCharacter*> getStage8() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies()};} //increased to 8 
    virtual vector<BaseCharacter*> getStage9() override {return vector<BaseCharacter*>{player, new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies(), new Fairies()};} // these will be very strong
    virtual vector<BaseCharacter*> getStage10() override {return vector<BaseCharacter*>{player, new Zombies()};} //boss however we make it
   
};

#endif
