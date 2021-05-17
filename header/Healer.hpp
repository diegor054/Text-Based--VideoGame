#ifndef __HEALER_HPP__
#define __HEALER_HPP__
#include "Player.hpp"

//implement attacker  class

class Healer: public BaseCharacter{
        private:
        string wandType; //goes wood, steel, gold, diamond. used just for show not any purpose. propotional to playerTypeLevel
        public:
        Healer(): health(200),xp(0), weaponType("Wand"), playerTypeLevel(0), wandType("Wood") {}
        void Upgrade() override{
        //implement
        }
        void setMaxHealth() const override{
        health = 200;
        }
        void attack(vector<Opponent*> opp) override{
        //implement
        }
    };
                                                             
#endif

