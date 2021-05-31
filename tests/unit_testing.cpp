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
#include "../header/LeftPathFactory.hpp"
#include "../header/AttackerFactory.hpp"
#include "../header/HealerFactory.hpp"
#include "../header/NinjaFactory.hpp"
#include "../header/AbstractPlayerFactory.hpp"


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
/*
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
*/
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

TEST(AbilityDecorator, testingFunctions){
	BaseCharacter* t = new Attacker();
	BaseCharacter* temp = new DodgeDecorator(t);
	EXPECT_EQ(temp->getName(), "Null");
	EXPECT_EQ(temp->getType(), "Attacker");
	EXPECT_EQ(temp->getHealth(), 100);
	EXPECT_EQ(temp->getXP(), 0);
	EXPECT_EQ(temp->getLatestDamage(), 0);
	EXPECT_EQ(temp->getAttackStrength(), 10);
  	EXPECT_EQ(temp->getLevel(), 0);
	EXPECT_EQ(temp->getHealthBar(), "[||||||||||]");
	delete t;
	delete temp;
}
TEST(AbilityDecorator, testingSetters){
	BaseCharacter* t = new Attacker();
        BaseCharacter* temp = new DodgeDecorator(t);
       	temp->setName("B");
        temp->setXP(10);
        temp->setHealth(23);
        temp->setType("Ninja");	
	EXPECT_EQ(temp->getName(), "B");
        EXPECT_EQ(temp->getType(), "Ninja");
        EXPECT_EQ(temp->getHealth(), 23);
        EXPECT_EQ(temp->getXP(), 10);
	delete t;
	delete temp;
}
TEST(StageFactories, testSize){
	BaseCharacter* temp = new Attacker();
	AbstractStageFactory* l = new LeftPathFactory(temp);
	vector<BaseCharacter*> vec = l->getStage10();
	EXPECT_EQ(vec.size(), 2);
	for(int i = 0; i < vec.size(); i++){
      	   delete vec.at(i);
       }
	delete l;
}
TEST(PlayerFactories, testInfo){
	AbstractPlayerFactory* a = new AttackerFactory();
	AbstractPlayerFactory* n = new NinjaFactory();
	AbstractPlayerFactory* h = new HealerFactory();
	EXPECT_EQ(a->getPlayerInfo(), "You are the Attacker. You are strong, and have the chance to deal extra damage on the opponent. You also have armor which will protect you from your opponents.");
	EXPECT_EQ(n->getPlayerInfo(),"You are the Ninja. Your agility helps you to stealthily avoid some of the enemies attacks. You also have shurikens which can damage multiple opponents at once.");
	EXPECT_EQ(h->getPlayerInfo(),"You are the Healer. Your magical abilities allow you to drain the opponent of their health while healing yours. You also have spikes which will damage the opponent when they attack you.");
	delete a;
	delete n;
	delete h;
}











