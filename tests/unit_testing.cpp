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
    vector<BaseCharacter*>vec{temp, new Zombies(), new Zombies(), new Zombies(), new Zombies()};
     temp->attack(vec, 0);
    while(temp->getLatestDamage() == temp->getAttackStrength()){
	temp->attack(vec, 0);
    }
    EXPECT_EQ(temp->getLatestDamage(), 15);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}

TEST(ArmorDecoratorTest, testingDamageTaken) {
    BaseCharacter* temp = new ArmorDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    int result = (temp->getHealth() - (vec.at(1)->getAttackStrength() / 2));
    vec.at(1)->attack(vec, 1);
    EXPECT_EQ(temp->getHealth(), result);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}

TEST(DrainDecoratorTest, testingDamageTaken) {
    BaseCharacter* temp = new DrainDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies()};
    vec.at(1)->attack(vec, 1);
    int result = (temp->getHealth() + (vec.at(1)->getLatestAttack() / 5));
    temp->attack(vec, 0);
    EXPECT_EQ(temp->getHealth(), result);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}




















