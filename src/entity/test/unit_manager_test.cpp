#include "unit_manager.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(CreateUnitManager, CreateUnitManager1)
{
    UnitManager unitManager;
}

TEST(IncrementNumberOfPlayers, IncrementNumberOfPlayers1)
{
    UnitManager unitManager;
    unsigned int startNumPlayers = unitManager.GetNumberOfPlayers();
    unitManager.IncrementNumberOfPlayers();
    ASSERT_EQ(startNumPlayers + 1, unitManager.GetNumberOfPlayers());
}

TEST(DecrementNumberOfPlayers, DecrementNumberOfPlayers1)
{
    UnitManager unitManager;
    unsigned int startNumPlayers = unitManager.GetNumberOfPlayers();
    unitManager.IncrementNumberOfPlayers();
    ASSERT_EQ(startNumPlayers + 1, unitManager.GetNumberOfPlayers());
    unitManager.DecrementNumberOfPlayers();
    ASSERT_EQ(startNumPlayers, unitManager.GetNumberOfPlayers());
}

TEST(UnitManager_CreatePlayer, UnitManager_CreatePlayer1)
{
    UnitManager unitManager;
    unitManager.CreatePlayer("testUser");
}
