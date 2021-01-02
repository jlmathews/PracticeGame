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
        auto val = redis->get(NumberPlayersKey);
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

    std::string UnitManager::GetPlayerUuid(std::string playerName)
    {
        std::vector<std::string> playerList;
        std::string playerUuid;

        spdlog::debug("Get Player UUID: {}", playerName);

        redis->smembers(playerListKey, std::back_inserter(playerList));

        for(auto tempPlayerUuid: playerList)
        {
            spdlog::debug("Player UUID: {}", tempPlayerUuid);
            std::vector<OptionalString> tempPlayerName;
            redis->hmget(tempPlayerUuid, {"name"}, std::back_inserter(tempPlayerName));
            if(tempPlayerName.size() > 0 && tempPlayerName[0])
            {
                if(playerName == tempPlayerName[0].value())
                {
                    spdlog::debug("Found Player: {}, {}", tempPlayerName[0].value(), tempPlayerUuid);
                    playerUuid = tempPlayerUuid;
                    break;
                }
            }
        }

        if(playerUuid == "")
        {
            spdlog::warn("Cannot find player {}.", playerName);
        }

        return playerUuid;
    }

    void UnitManager::IncrementNumberOfPlayers()
    {
        spdlog::debug("Increment number of players.");

        if(GetNumberOfPlayers() == 0)
        {
            redis->set(NumberPlayersKey, "1");
        }
        else
        {
            redis->incr(NumberPlayersKey);
        }
    }

    void UnitManager::DecrementNumberOfPlayers()
    {
        spdlog::debug("Decrement number of players.");

        if(GetNumberOfPlayers() > 0)
        {
            redis->decr(NumberPlayersKey);
        }
        else
        {
            spdlog::warn("Cannot decrement number of players. Already 0.");
        }
    }

    bool UnitManager::CreatePlayer(std::string playerName)
    {
        spdlog::debug("Create Player: {}", playerName);

        if(GetPlayerUuid(playerName) != "")
        {
            spdlog::warn("Cannot create player {}.", playerName);
            return false;
        }

        auto playerUuid = UuidGenerator::GenerateUuid();

        redis->hmset(playerUuid,
        {
            std::make_pair(playerNameKey, playerName),
        });

        IncrementNumberOfPlayers();

        redis->sadd(playerListKey, {playerUuid});

        return true;
    }

    bool UnitManager::DeletePlayer(std::string playerName)
    {
        std::string playerUuid;

        spdlog::debug("Delete Player: {}", playerName);

        playerUuid = GetPlayerUuid(playerName);

        if(playerUuid == "")
        {
            spdlog::warn("Cannot delete player {}.", playerName);
            return false;
        }

        DecrementNumberOfPlayers();

        redis->srem(playerListKey, playerUuid);

        return true;
    }

    void UnitManager::Reset()
    {
        redis->flushall();
    }
}
