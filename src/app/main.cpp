
#include "character_manager.h"
#include "player_manager.h"

#include "spdlog/spdlog.h"

using namespace PGame;

void menu()
{
    std::shared_ptr<IStorage<RedisAdapter>> storage;
    storage = std::make_shared<IStorage<RedisAdapter>>("app1");
    PlayerManager playerManager(storage);

    spdlog::info("Number of Players: {}", playerManager.GetNumberOfPlayers());

    std::vector<std::string> existingPlayers;
    playerManager.ListPlayers(existingPlayers);
    spdlog::info("Existing players:");
    for(auto player: existingPlayers)
    {
        spdlog::info("- {}", player);
    }
}

int main()
{
    spdlog::info("Start main.");

    menu();

    return 0;
}
