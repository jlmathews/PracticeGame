#include "character_manager.h"

#include "gtest/gtest.h"

using namespace PGame;

class CharacterManagerTest : public ::testing::Test
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

TEST_F(CharacterManagerTest, CharacterManager_CreateCharacter_OnePlayer)
{
    CharacterManager characterManager(storage);
    ASSERT_EQ(true, characterManager.CreateCharacter("TestChar", "TestClass", true));
}

TEST_F(CharacterManagerTest, CharacterManager_CreateCharacter_DuplicatePlayer)
{
    CharacterManager characterManager(storage);
    ASSERT_EQ(true, characterManager.CreateCharacter("TestChar", "TestClass", true));
    ASSERT_EQ(false, characterManager.CreateCharacter("TestChar", "TestClass", true));
}

TEST_F(CharacterManagerTest, CharacterManager_GetNumberOfCharacters_NoPlayers)
{
    CharacterManager characterManager(storage);
    ASSERT_EQ(0, characterManager.GetNumberOfCharacters());
}

TEST_F(CharacterManagerTest, CharacterManager_GetNumberOfCharacters_OnePlayer)
{
    CharacterManager characterManager(storage);
    ASSERT_EQ(0, characterManager.GetNumberOfCharacters());
    ASSERT_EQ(true, characterManager.CreateCharacter("TestChar", "TestClass", true));
    ASSERT_EQ(1, characterManager.GetNumberOfCharacters());
}