
#include "character_manager.h"
#include "player_manager.h"

#include "spdlog/spdlog.h"

using namespace PGame;

int main()
{
    spdlog::info("Start main.");

    std::shared_ptr<IStorage<RedisAdapter>> storage;
    storage = std::make_shared<IStorage<RedisAdapter>>("app");
    PlayerManager playerManager(storage);

    return 0;
}
