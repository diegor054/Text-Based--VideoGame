#include "../header/Attacker.hpp"
#include "../header/Healer.hpp"
#include "../header/Ninja.hpp"
#include "../header/AoeDecorator.hpp"
#include "../header/ArmorDecorator.hpp"
#include "../header/CriticalDecorator.hpp"
#include "../header/DodgeDecorator.hpp"
#include "../header/DrainDecorator.hpp"
#include "../header/SpikesDecorator.hpp"
#include "../header/Zombies.hpp"
#include "../header/Goblins.hpp"
#include "../header/Fairies.hpp"
#include "../header/BaseCharacter.hpp"

#include <vector>
using namespace std;

TEST(AttackerTest, defaultAttacker) {
    Attacker* temp = new Attacker();
    EXPECT_EQ(temp->getHealth(), 100);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 10);
    EXPECT_EQ(temp->getType(), "Attacker");
    delete temp;
}
TEST(HealerTest, defaultHealer) {
    Healer* temp = new Healer();
    EXPECT_EQ(temp->getHealth(), 200);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 8);
    EXPECT_EQ(temp->getType(), "Healer");
    delete temp;
}
TEST(NinjaTest, defaultNinja) {
    Ninja* temp = new Ninja();
    EXPECT_EQ(temp->getHealth(), 100);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 8);
    EXPECT_EQ(temp->getType(), "Ninja");
    delete temp;
}

TEST(FairyTest, defaultFairy) {
    Fairies* temp = new Fairies();
    EXPECT_EQ(temp->getHealth(), 50);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 3);
    EXPECT_EQ(temp->getType(), "Fairy");
    delete temp;
}
TEST(GoblinTest, defaultGoblin) {
    Goblins* temp = new Goblins();
    EXPECT_EQ(temp->getHealth(), 50);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 2);
    EXPECT_EQ(temp->getType(), "Goblin");
    delete temp;
}
TEST(ZombieTest, defaultZombie) {
    Zombies* temp = new Zombies();
    EXPECT_EQ(temp->getHealth(), 25);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 5);
    EXPECT_EQ(temp->getType(), "Zombie");
    delete temp;
}
TEST(AttackerTest, testingDamageDone) {
    BaseCharacter* temp = new Attacker();
    vector<BaseCharacter*>vec{temp, new Zombies()};
     temp->attack(vec, 0);
    EXPECT_EQ(vec.at(1)->getHealth(), 15);
    for(int i = 0; i < vec.size(); i++){
        delete vec.at(i);
        }
}

TEST(HealerTest, testingDamageDone) {
    BaseCharacter* temp = new Healer();
    vector<BaseCharacter*>vec{temp, new Zombies()};
     temp->attack(vec, 0);
    EXPECT_EQ(vec.at(1)->getHealth(), 17);
    for(int i = 0; i < vec.size(); i++){
        delete vec.at(i);
        }
}

TEST(ninjaTest, testingDamageDone) {
    BaseCharacter* temp = new Ninja();
    vector<BaseCharacter*>vec{temp, new Zombies()};
     temp->attack(vec, 0);
    EXPECT_EQ(vec.at(1)->getHealth(), 17);
    for(int i = 0; i < vec.size(); i++){
        delete vec.at(i);
        }
}

TEST(CriticalTest, testingDamageDone) {
    BaseCharacter* temp = new CriticalDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
     BaseCharacter* victim;
     victim = vec.at(0)->attack(vec, 0);
    while(victim->getLatestDamage() == (vec.at(0)->getAttackStrength())){
          victim->refresh(false);
	 victim = vec.at(0)->attack(vec,0);   
 }
    EXPECT_EQ(victim->getLatestDamage(), temp->getAttackStrength() * (1.5));
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}

TEST(ArmorDecoratorTest, testingDamageTaken) {
    BaseCharacter* temp = new ArmorDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    while(temp->getLatestDamage() == vec.at(1)->getAttackStrength()){
             temp->refresh(true);
              vec.at(1)->attack(vec, 1);
    }
    int result = (temp->getHealth() - (temp->defend(vec,1,vec.at(1)->getAttackStrength())));
    EXPECT_EQ(temp->getHealth(), result);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
    }
}

TEST(DrainDecoratorTest, testingDamageTaken) {
    BaseCharacter* temp = new DrainDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    int current = temp->getHealth();
    while(temp->getHealth() == current){
    temp->attack(vec, 1);
    vec.at(1)->refresh(true);
    }
    int result = (temp->getHealth() + ((vec.at(1)->getLatestDamage() * (0.1492 + sqrt(0.02512 * temp->getLevel() + 0.00573168)) / 0.01256) / 100));
    EXPECT_EQ(temp->getHealth(), result);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}

TEST(SpikesDecoratorTest, testingDamageTaken) {
    BaseCharacter* temp = new SpikesDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    while(vec.at(1)->getHealth() == 100){
    temp->refresh(true);
    vec.at(1)->attack(vec, 1);
    }
    int result = (vec.at(1)->getHealth() - vec.at(1)->defend(vec,1, vec.at(1)->getAttackStrength()));
    EXPECT_EQ(vec.at(1)->getHealth(), result);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}

TEST(DodgeDecoratorTest, testDamageDodged){
    BaseCharacter* temp = new DodgeDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    bool dodgeFull = false;
    bool dodgeHalf = false; 
    vec.at(1)->attack(vec, 1);
    while(!dodgeFull && !dodgeHalf){ 
    temp->refresh(true);
    vec.at(1)->attack(vec, 1);
    if(temp->getLatestDamage() != vec.at(1)->getAttackStrength() && temp->getLatestDamage() && !dodgeHalf){
      EXPECT_EQ(temp->getLatestDamage(), vec.at(1)->getAttackStrength() /2 );
      dodgeHalf = true;
    }
   else if(temp->getLatestDamage() == 0 && !dodgeFull){
	EXPECT_EQ(temp->getLatestDamage(), 0);
	dodgeFull = true;
   }
  }
  for(int i = 0; i < vec.size(); i++){
        delete vec.at(i);
        }
}
   

TEST(AoeDecoratorTest, testDamageDone){
    BaseCharacter* temp = new AoeDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies(), new Zombies(), new Zombies(), new Zombies()};
    bool attackLanded = false;
    while(!attackLanded){
	 temp->attack(vec, 0);
         for(int i = 1; i < vec.size();i++){
	 if(vec.at(i)->getLatestDamage() != 0){
	   EXPECT_EQ(vec.at(i)->getHealth(), vec.at(i)->getHealth() - (temp->getAttackStrength() /3));
	attackLanded = true;
        }
        }
   }
   for(int i = 0; i < vec.size(); i++){
      delete vec.at(i);
   }
}

