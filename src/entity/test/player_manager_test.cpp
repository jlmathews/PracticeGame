#include "player_manager.h"

#include "gtest/gtest.h"

using namespace PGame;

class PlayerManagerTest : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            storage = std::make_shared<IStorage<RedisAdapter>>("test");
            storage->DeleteAll("test:*");
        }

        void TearDown() override
        {
            storage->DeleteAll("test:*");
        }

        std::shared_ptr<IStorage<RedisAdapter>> storage;
};

TEST_F(PlayerManagerTest, PlayerManager_CreatePlayer1)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_CreatePlayer2)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(false, playerManager.CreatePlayer("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_CreatePlayer3)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser1"));
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser2"));
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser3"));
}

TEST_F(PlayerManagerTest, PlayerManager_DeletePlayer1)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(true, playerManager.DeletePlayer("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_DeletePlayer2)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(true, playerManager.DeletePlayer("PlayerManager:testUser"));
    ASSERT_EQ(false, playerManager.DeletePlayer("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_DeletePlayer3)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(false, playerManager.DeletePlayer("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_GetPlayerUuid1)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ("", playerManager.GetPlayerUuid("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_GetPlayerUuid2)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_NE("", playerManager.GetPlayerUuid("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_GetPlayerUuid3)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(true, playerManager.DeletePlayer("PlayerManager:testUser"));
    ASSERT_EQ("", playerManager.GetPlayerUuid("PlayerManager:testUser"));
}

TEST_F(PlayerManagerTest, PlayerManager_GetNumberOfPlayers1)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(0, playerManager.GetNumberOfPlayers());
}

TEST_F(PlayerManagerTest, PlayerManager_GetNumberOfPlayers2)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(0, playerManager.GetNumberOfPlayers());
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(1, playerManager.GetNumberOfPlayers());
}

TEST_F(PlayerManagerTest, PlayerManager_GetNumberOfPlayers3)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(0, playerManager.GetNumberOfPlayers());
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser"));
    ASSERT_EQ(true, playerManager.DeletePlayer("PlayerManager:testUser"));
    ASSERT_EQ(0, playerManager.GetNumberOfPlayers());
}

TEST_F(PlayerManagerTest, PlayerManager_GetNumberOfPlayers4)
{
    PlayerManager playerManager(storage);
    ASSERT_EQ(0, playerManager.GetNumberOfPlayers());
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser1"));
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser2"));
    ASSERT_EQ(true, playerManager.CreatePlayer("PlayerManager:testUser3"));
    ASSERT_EQ(3, playerManager.GetNumberOfPlayers());
}
