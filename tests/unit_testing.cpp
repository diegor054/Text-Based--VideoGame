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
TEST(CriticalTest, testingDamageDone) {
    BaseCharacter* temp = new CriticalDecorator(new Attacker());
    vector<BaseCharacter*>vec{temp, new Zombies(), new Zombies(), new Zombies(), new Zombies()};
    while(temp->getLatestDamage() == temp->getAttackStrength()){
	temp->attack(vec, 0);
    }
    EXPECT_EQ(temp->getLatestDamage(), 15);
    for(int i = 0; i < vec.size(); i++){
	delete vec.at(i);
	}
}























