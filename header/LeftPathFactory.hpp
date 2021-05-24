#ifndef __LEFT_PATH_FACTORY__
#define __LEFT_PATH_FACTORY__

#include "AbstractStageFactory.hpp"

class LeftPathFactory : public AbstractStageFactory {
 public:
    LeftPathFactory(Player* user) : AbstractStageFactory(user) { }
    virtual vector<BaseCharacter*> getStage1() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage2() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage3() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage4() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage5() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage6() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage7() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage8() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage9() override {return vector<BaseCharacter*>{player, new Opponent()}};
    virtual vector<BaseCharacter*> getStage10() override {return vector<BaseCharacter*>{player, new Opponent()}};
};

#endif