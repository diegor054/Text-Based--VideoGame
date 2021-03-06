#ifndef __ABSTRACT_PLAYER_FACTORY__
#define __ABSTRACT_PLAYER_FACTORY__

#include <string>

using namespace std;

#include "Player.hpp"

class AbstractPlayerFactory {
 protected:
    string playerInfo;
    virtual BaseCharacter* addDecorators(Player*) = 0;
 public:
    AbstractPlayerFactory() { };
    virtual BaseCharacter* getDefaultPlayer() = 0;
    virtual BaseCharacter* getUpgradedPlayer(const string &, int) = 0;
    virtual string getPlayerInfo() = 0;
};

#endif
