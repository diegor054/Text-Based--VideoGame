#ifndef __RIGHT_PATH_FACTORY__
#define __RIGHT_PATH_FACTORY__

#include "AbstractStageFactory"

class RightPathFactory : public AbstractStageFactory {
 public:
    RightPathFactory(Player* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage2() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage3() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage4() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage5() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage6() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage7() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage8() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage9() {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage10() {return vector<BaseCharacter*>{player, new Opponent()}};
};

#endif