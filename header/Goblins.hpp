#ifndef __GOBLINS_HPP__
#define __GOBLINS_HPP__

class Goblins: public Opponent{
        private:

        public:
        Golbins(): opponentLevel(1), attackStyle("Knife"), health(50), name("Goblins"), attackStrength(2){}
        void attack(vector<Opponent*> opp) override{
        if(this->health > 0){
        opponent.at(0).setHealth(attackStrength * -1);
        damageMessage(attackStrength);
        }
	}

	void damageMessages(int damage){
	int num = (rand() % 3) + 1;
	if(num == 1){
	cout << "Goblem knife you and took off " << damage << " damage!" << endl;
	}
	if(num == 2){
	cout << "Goblem hit you hard! You lost " << damage << " health!" << endl;; 
	}
	if(num == 3){
	cout << "Goblem is very mad at you and attacked you for " << damage << " health!" << endl;
	}
	}	
}


#endif

