#ifndef __ABSTRACT_PLAYER_FACTORY__
#define __ABSTRACT_PLAYER_FACTORY__

#include <string>

using namespace std;

#include "Player.hpp"

class AbstractPlayerFactory {
 protected:
    string playerInfo;
    virtual Player* addDecorators(Player*) = 0;
 public:
    AbstractPlayerFactory();
    virtual Player* getDefaultPlayer() = 0;
    virtual Player* getUpgradedPlayer(const string &, int) = 0;
    string getPlayerInfo() { return playerInfo; }
};

#endif