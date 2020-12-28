#include "damage.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(CreateDamage, CreateDamage1)
{
    Damage damage;

    damage.AddDamage(DamageType_e::PHYSICAL, 10, 25);
    damage.AddDamage(DamageType_e::PHYSICAL, 17, 35);
    damage.AddDamage(DamageType_e::PHYSICAL, 23, 45);
    damage.Print();
}
