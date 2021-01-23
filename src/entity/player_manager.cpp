#include "player_manager.h"
#include "uuid_generator.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    PlayerManager::PlayerManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage)
    {
        spdlog::info("Create PlayerManager");
        storage = inputStorage;
    }

    /**
     * Get number of players registered with unit manager
     * 
     * @returns number of players
     */
    unsigned int PlayerManager::GetNumberOfPlayers()
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

    /**
     * Get UUID of player from players name
     * 
     * @param   playerName is the player name
     * @returns Player UUID as string
     */
    std::string PlayerManager::GetPlayerUuid(std::string playerName)
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

    /**
     * Increment number of players starting at zero.
     */
    void PlayerManager::IncrementNumberOfPlayers()
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

    /**
     * Decrement number of players. Number of players can't be less than zero.
     */
    void PlayerManager::DecrementNumberOfPlayers()
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

    /**
     * Generate a player with the specified name and save to storage.
     * 
     * @param   playerName is the player name
     * @returns true if successfully generated the player. false otherwise.
     */
    bool PlayerManager::GeneratePlayer(std::string playerName)
    {
        auto playerUuid = UuidGenerator::GenerateUuid();

        storage->HashSet(playerUuid,
        {
            std::make_pair(playerNameKey, playerName),
        });

        IncrementNumberOfPlayers();

        storage->SetAdd(playerListKey, playerUuid);

        return true;
    }

    /**
     * Create a player with the specified name and save to storage.
     *
     * @param   playerName is the player name
     * @returns true if successfully created the player. false otherwise.
     */
    bool PlayerManager::CreatePlayer(std::string playerName)
    {
        spdlog::debug("Create Player: {}", playerName);

        // If player exists, then cannot create player with same name.
        if(PlayerExists(playerName))
        {
            spdlog::warn("Cannot create player {}. Name already exists.", playerName);
            return false;
        }

        if(!GeneratePlayer(playerName))
        {
            spdlog::error("Failed to create player {}.", playerName);
            return false;
        }

        return true;
    }

    /**
     * Delete a player with the specified name from storage.
     *
     * @param   playerName is the player name
     * @returns true if successfully deleted the player. false otherwise.
     */
    bool PlayerManager::DeletePlayer(std::string playerName)
    {
        std::string playerUuid;

        spdlog::debug("Delete Player: {}", playerName);

        if(!PlayerExists(playerName))
        {
            spdlog::warn("Cannot delete player {}.", playerName);
            return false;
        }

        playerUuid = GetPlayerUuid(playerName);

        DecrementNumberOfPlayers();

        storage->SetRemove(playerListKey, playerUuid);

        return true;
    }

    /**
     * Check if player exists.
     *
     * @param   playerName is the player name
     * @returns true if player exists. false otherwise.
     */
    bool PlayerManager::PlayerExists(std::string playerName)
    {
        // If empty string is returned, then player does not exist.
        if("" == GetPlayerUuid(playerName))
        {
            return false;
        }

        return true;
    }

    void PlayerManager::ListPlayers(std::vector<std::string> &players)
    {
        std::vector<std::string> playerList;

        // Get list of player UUID's
        storage->SetMembers(playerListKey, playerList);

        for(auto tempPlayerUuid: playerList)
        {
            std::string tempPlayerName;
            storage->HashGet(tempPlayerUuid, playerNameKey, tempPlayerName);
            spdlog::debug("Player UUID: {}, Name: {}", tempPlayerUuid, tempPlayerName);
            players.push_back(tempPlayerName);
        }
    }
}
