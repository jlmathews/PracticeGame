#include "gtest/gtest.h"
#include "position.h"
#include "unit.h"

TEST(CreateUnit, CreateUnit1)
{
    PGame::Unit unit;
}

TEST(CreateUnit, MoveUnit1)
{
    PGame::Unit unit;
    PGame::Position* position;

    unit.Move(1, 5);
    unit.Move(3, 2);

    position = unit.GetPosition();
    ASSERT_EQ(4, position->X());
    ASSERT_EQ(7, position->Y());
    position->Print();
}