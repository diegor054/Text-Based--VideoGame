#ifndef __ZOMBIES_HPP__
#define __ZOMBIES_HPP__

class Zombies: public Opponent{
	private:
	
	public:
	Zombies(): opponentLevel(1), attackStyle("Fist"), health(25), name("Zombies"), attackStrength(5){}  
	void attack(vector<Opponent*> opp) override { //the idea of making player index 0 is good but wouldnt the vector have to be BaseCharacters since player isnt an 	//opoenent
	if(this->health > 0){
	opponent.at(0).setHealth(-5); 	
	cout << "A zombie just attacked you and did 5 damage!" << endl;
	}
	}

}


#endif
