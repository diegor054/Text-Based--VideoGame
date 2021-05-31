#ifndef __ABSTRACT_STAGE_FACTORY__
#define __ABSTRACT_STAGE_FACTORY__

#include <vector>

using namespace std;

#include "Player.hpp"
#include "Opponent.hpp"
#include "Zombie.hpp"
#include "Goblin.hpp"
#include "Fairy.hpp"

class AbstractStageFactory {
 protected:
    BaseCharacter* player;
 public:
    AbstractStageFactory(BaseCharacter* user) : player(user) { }
    virtual vector<BaseCharacter*> getStage1() = 0;
    virtual vector<BaseCharacter*> getStage2() = 0;
    virtual vector<BaseCharacter*> getStage3() = 0;
    virtual vector<BaseCharacter*> getStage4() = 0;
    virtual vector<BaseCharacter*> getStage5() = 0;
    virtual vector<BaseCharacter*> getStage6() = 0;
    virtual vector<BaseCharacter*> getStage7() = 0;
    virtual vector<BaseCharacter*> getStage8() = 0;
    virtual vector<BaseCharacter*> getStage9() = 0;
    virtual vector<BaseCharacter*> getStage10() = 0;
};

#endif