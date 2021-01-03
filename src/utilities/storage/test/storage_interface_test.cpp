#include "redis_adapter.h"
#include "storage_interface.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(IStorage_Create, IStorage_Create1)
{
    IStorage<RedisAdapter> storage("test");
}

TEST(IStorage_DeleteAll, IStorage_DeleteAll1)
{
    IStorage<RedisAdapter> storage("test");
    storage.DeleteAll("test:*");
}
