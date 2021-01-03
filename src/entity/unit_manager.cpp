#include "unit_manager.h"
#include "uuid_generator.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    UnitManager::UnitManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage)
    {
        spdlog::info("Create UnitManager");
        storage = inputStorage;
    }

    unsigned int UnitManager::GetNumberOfPlayers()
    {
        auto val = storage->GetValue(NumberPlayersKey);
        unsigned int numberOfPlayers = 0;

        if(val != "")
        {
            spdlog::info("Number of players: {}", val);
            numberOfPlayers = std::stoi(val);
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

        storage->SetMembers(playerListKey, playerList);

        for(auto tempPlayerUuid: playerList)
        {
            spdlog::debug("Player UUID: {}", tempPlayerUuid);
            std::string tempPlayerName;
            storage->HashGet(tempPlayerUuid, playerNameKey, tempPlayerName);
            if(playerName == tempPlayerName)
            {
                spdlog::debug("Found Player: {}, {}", tempPlayerName, tempPlayerUuid);
                playerUuid = tempPlayerUuid;
                break;
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
            storage->SetValue(NumberPlayersKey, "1");
        }
        else
        {
            storage->Increment(NumberPlayersKey);
        }
    }

    void UnitManager::DecrementNumberOfPlayers()
    {
        spdlog::debug("Decrement number of players.");

        if(GetNumberOfPlayers() > 0)
        {
            storage->Decrement(NumberPlayersKey);
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

        storage->HashSet(playerUuid,
        {
            std::make_pair(playerNameKey, playerName),
        });

        IncrementNumberOfPlayers();

        storage->SetAdd(playerListKey, playerUuid);

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

        storage->SetRemove(playerListKey, playerUuid);

        return true;
    }
}
