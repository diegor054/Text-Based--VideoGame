#ifndef __ZOMBIES_HPP__
#define __ZOMBIES_HPP__

class Zombies: public Opponent{
	private:
	
	public:
	Zombies(): opponentLevel(1), attackStyle("Fist"), health(25), name("Zombies"), attackStrength(5){}  
	void attack(vector<Opponent*> opp) override { //the idea of making player index 0 is good but wouldnt the vector have to be BaseCharacters since player isnt an 	//opoenent
	if(this->health > 0){
	opponent.at(0).setHealth(attackStrength * -1); 	
	damageMessages(attackStrength);
	}
	}
	void damageMessages(int damage){
        int num = (rand() % 3) + 1;
        if(num == 1){
        cout << "Zombie punched you and took off " << damage << " damage!" << endl;
        }
        if(num == 2){
        cout << "ERRRR. Zombie hit you hard! You lost " << damage << " health!" << endl;;
        }
        if(num == 3){
        cout << "Zombie wants some fresh meat. He attacked you for " << damage << " health!" << endl;
        }
        }


}


#endif
