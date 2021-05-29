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
using namespace std;

TEST(AttackerTest, defaultAttacker) {
    Attacker* temp = new Attacker();
    EXPECT_EQ(temp->getHealth(), 100);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 10);
    EXPECT_EQ(temp->Type(), "Attacker");
    delete temp;
}
TEST(HealerTest, defaultHealer) {
    Healer* temp = new Healer();
    EXPECT_EQ(temp->getHealth(), 200);
    EXPECT_EQ(temp->getXP() , 0);
    EXPECT_EQ(temp->getAttackStrength(), 8);
    EXPECT_EQ(temp->Type(), "Healer");
    delete temp;
}

