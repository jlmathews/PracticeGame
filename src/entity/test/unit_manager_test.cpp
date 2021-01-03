#include "unit_manager.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(CreateUnitManager, CreateUnitManager1)
{
    UnitManager unitManager;
}

TEST(UnitManager_CreatePlayer, UnitManager_CreatePlayer1)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(true, unitManager.CreatePlayer("testUser"));
}

TEST(UnitManager_CreatePlayer, UnitManager_CreatePlayer2)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(true, unitManager.CreatePlayer("testUser"));
    unitManager.CreatePlayer("testUser");
}

TEST(UnitManager_DeletePlayer, UnitManager_DeletePlayer1)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(true, unitManager.CreatePlayer("testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("testUser"));
}

TEST(UnitManager_DeletePlayer, UnitManager_DeletePlayer2)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(true, unitManager.CreatePlayer("testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("testUser"));
    ASSERT_EQ(false, unitManager.DeletePlayer("testUser"));
}

TEST(UnitManager_DeletePlayer, UnitManager_DeletePlayer3)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(false, unitManager.DeletePlayer("testUser"));
}

TEST(UnitManager_GetPlayerUuid, UnitManager_GetPlayerUuid1)
{
    UnitManager unitManager;
    unitManager.Reset();
    ASSERT_EQ(true, unitManager.CreatePlayer("testUser"));
    ASSERT_NE("", unitManager.GetPlayerUuid("testUser"));
}
