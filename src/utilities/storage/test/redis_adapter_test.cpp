#include "redis_adapter.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(RedisAdapter_Create, RedisAdapter_Create1)
{
    RedisAdapter adapter;
}

TEST(RedisAdapter_DeleteAll, RedisAdapter_DeleteAll1)
{
    RedisAdapter adapter;
    adapter.DeleteAll("test:*");
    ASSERT_EQ(1, adapter.SetValue("test", "setValue", "testValue"));
    ASSERT_EQ(true, adapter.DeleteAll("test:*"));
    ASSERT_EQ(false, adapter.DeleteAll("test:*"));
}
