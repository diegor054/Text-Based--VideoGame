#ifndef __GOBLINS_HPP__
#define __GOLBINS_HPP__

class Goblins: public Opponent{
        private:

        public:
        Golbins(): opponentLevel(1), attackStyle("Knife"), health(50), name("Goblins"), attackStrength(2){}
        void attack(vector<Opponent*> opp) override{
        if(this->health > 0){
        opponent.at(0).setHealth(-2);
        cout << "A Golbin just knifed you and did 2 damage!" << endl;
        }
        }

}


#endif

