#ifndef __OPPONENT_HPP__
#define __OPPONENT_HPP__

#include "BaseCharacter.hpp"

class Opponent: public BaseCharacter {
 protected:
	int opponentLevel;
	string attackStyle;
 public:
	Opponent() { }
};

#endif
