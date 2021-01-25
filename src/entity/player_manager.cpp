#include "player_manager.h"
#include "uuid_generator.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    PlayerManager::PlayerManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage)
    {
        spdlog::info("Create PlayerManager");
        unitManager = std::make_unique<UnitManager>(inputStorage, NumberPlayersKey, playerListKey, playerNameKey);
    }

    /**
     * Get number of players registered with unit manager
     * 
     * @returns number of players
     */
    unsigned int PlayerManager::GetNumberOfPlayers()
    {
        return unitManager->GetNumberOfUnits();
    }

    /**
     * Get UUID of player from players name
     * 
     * @param   playerName is the player name
     * @returns Player UUID as string
     */
    std::string PlayerManager::GetPlayerUUID(std::string playerName)
    {
        spdlog::debug("Get Player UUID: {}", playerName);
        return unitManager->GetUnitUuid(playerName);
    }

    /**
     * Increment number of players starting at zero.
     */
    void PlayerManager::IncrementNumberOfPlayers()
    {
        spdlog::debug("Increment number of players.");
        unitManager->IncrementNumberOfUnits();
    }

    /**
     * Decrement number of players. Number of players can't be less than zero.
     */
    void PlayerManager::DecrementNumberOfPlayers()
    {
        spdlog::debug("Decrement number of players.");
        unitManager->DecrementNumberOfUnits();
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

        return unitManager->CreateUnit(playerName,
        {
            std::make_pair(playerNameKey, playerName),
        });
    }

    /**
     * Delete a player with the specified name from storage.
     *
     * @param   playerName is the player name
     * @returns true if successfully deleted the player. false otherwise.
     */
    bool PlayerManager::DeletePlayer(std::string playerName)
    {
        spdlog::debug("Delete Player: {}", playerName);
        return unitManager->DeleteUnit(playerName);
    }

    /**
     * Check if player exists.
     *
     * @param   playerName is the player name
     * @returns true if player exists. false otherwise.
     */
    bool PlayerManager::PlayerExists(std::string playerName)
    {
        return unitManager->UnitExists(playerName);
    }

    void PlayerManager::ListPlayers(std::vector<std::string> &players)
    {
        unitManager->ListUnits(players);
    }
}