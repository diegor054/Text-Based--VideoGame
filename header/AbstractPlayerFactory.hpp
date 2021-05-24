#ifndef __ABSTRACT_PLAYER_FACTORY__
#define __ABSTRACT_PLAYER_FACTORY__

#include <string>

using namespace std;

#include "Player.hpp"

class AbstractPlayerFactory {
 private:
    string type;
 public:
    AbstractPlayerFactory();
    virtual Player* getDefaultPlayer() = 0;
    virtual Player* getUpgradedPlayer(const string &, const string &, const string &) = 0;
    virtual string getPlayerInfo() = 0;
};

#endif