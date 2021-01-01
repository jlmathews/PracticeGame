#include "unit_manager.h"
#include "uuid_generator.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    UnitManager::UnitManager()
    {
        spdlog::info("Create UnitManager");
        redis = std::make_unique<Redis>("tcp://127.0.0.1:6379");
    }

    unsigned int UnitManager::GetNumberOfPlayers()
    {
        auto val = redis->get("UnitManager:NumberPlayers");
        unsigned int numberOfPlayers = 0;

        if(val)
        {
            spdlog::info("Number of players: {}", val.value());
            numberOfPlayers = std::stoi(val.value());
        }
        else
        {
            spdlog::warn("Number of players not created yet.");
        }

        return numberOfPlayers;
    }

    void UnitManager::IncrementNumberOfPlayers()
    {
        spdlog::debug("Increment number of players.");

        if(GetNumberOfPlayers() == 0)
        {
            redis->set("UnitManager:NumberPlayers", "1");
        }
        else
        {
            redis->incr("UnitManager:NumberPlayers");
        }
    }

    void UnitManager::DecrementNumberOfPlayers()
    {
        spdlog::debug("Decrement number of players.");

        if(GetNumberOfPlayers() > 0)
        {
            redis->decr("UnitManager:NumberPlayers");
        }
        else
        {
            spdlog::warn("Cannot decrement number of players. Already 0.");
        }
    }

    void UnitManager::CreatePlayer(std::string playerName)
    {
        auto playerUuid = UuidGenerator::GenerateUuid();

        spdlog::debug("Create Player: {}", playerUuid);
        redis->hmset(playerUuid,
        {
            std::make_pair("name", playerName),
        });

        IncrementNumberOfPlayers();
    }
}
