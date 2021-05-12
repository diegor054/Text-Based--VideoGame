#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP_


//implement base class

class BaseCharacter{
private:
int health;  
int attackStrength;
public:
//should it be virtual so that each character has their unique attack style??
virtual void attackOpponent(Opponent* opp) = 0;

void printHealth() const {
   int lines = health / 10;
   int totalLines = 10;
   int spacesLeft = totalLines - lines;
   cout << "----------" << endl;
   for(int i = 0; i < lines; i++){
	cout << "|";
   }
   for(int i = 0; i < spacesLeft;i++){
	cout << " ";
	}
   cout << "|  " << health << "remaining health" << endl;
   cout << "----------" << endl;   
}

};
#endif
