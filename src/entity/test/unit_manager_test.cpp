#include "unit_manager.h"

#include "gtest/gtest.h"

using namespace PGame;

class UnitManagerTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            storage = std::make_shared<IStorage<RedisAdapter>>("test");
            storage->DeleteAll("test:*");
        }

        void TearDown() override
        {
            //storage->DeleteAll("test:*");
        }

        std::shared_ptr<IStorage<RedisAdapter>> storage;
};

TEST_F(UnitManagerTest, UnitManager_CreatePlayer1)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_CreatePlayer2)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(false, unitManager.CreatePlayer("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_CreatePlayer3)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser1"));
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser2"));
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser3"));
}

TEST_F(UnitManagerTest, UnitManager_DeletePlayer1)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_DeletePlayer2)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("UnitManager:testUser"));
    ASSERT_EQ(false, unitManager.DeletePlayer("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_DeletePlayer3)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(false, unitManager.DeletePlayer("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_GetPlayerUuid1)
{
    UnitManager unitManager(storage);
    ASSERT_EQ("", unitManager.GetPlayerUuid("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_GetPlayerUuid2)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_NE("", unitManager.GetPlayerUuid("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_GetPlayerUuid3)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("UnitManager:testUser"));
    ASSERT_EQ("", unitManager.GetPlayerUuid("UnitManager:testUser"));
}

TEST_F(UnitManagerTest, UnitManager_GetNumberOfPlayers1)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(0, unitManager.GetNumberOfPlayers());
}

TEST_F(UnitManagerTest, UnitManager_GetNumberOfPlayers2)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(0, unitManager.GetNumberOfPlayers());
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(1, unitManager.GetNumberOfPlayers());
}

TEST_F(UnitManagerTest, UnitManager_GetNumberOfPlayers3)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(0, unitManager.GetNumberOfPlayers());
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser"));
    ASSERT_EQ(true, unitManager.DeletePlayer("UnitManager:testUser"));
    ASSERT_EQ(0, unitManager.GetNumberOfPlayers());
}

TEST_F(UnitManagerTest, UnitManager_GetNumberOfPlayers4)
{
    UnitManager unitManager(storage);
    ASSERT_EQ(0, unitManager.GetNumberOfPlayers());
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser1"));
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser2"));
    ASSERT_EQ(true, unitManager.CreatePlayer("UnitManager:testUser3"));
    ASSERT_EQ(3, unitManager.GetNumberOfPlayers());
}
