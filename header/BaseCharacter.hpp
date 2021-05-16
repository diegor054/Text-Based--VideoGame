#ifndef __BASECHARACTER_HPP__
#define __BASECHARACTER_HPP__

#include "string"

class BaseCharacter{
private:
string name;
int health;  
int attackStrength;
public:

virtual void attack(vector<Opponent*> opp) = 0;
void printHealth() const {
   int lines = health / 10;
   int totalLines = 10;
   int spacesLeft = totalLines - lines;
   cout << "[";
   for(int i = 0; i < lines; i++){
	cout << "|";
   }
   for(int i = 0; i < spacesLeft;i++){
	cout << " ";
	}
   cout << "]  " << health << "remaining health" << endl;
   
}

};
#endif
