#pragma once

#include "redis_adapter.h"
#include "storage_interface.h"
#include "unit_manager.h"

#include <string>
#include <memory>

namespace PGame
{
    /**
     * Unit manager class
     */
    class PlayerManager
    {
        public:
            PlayerManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage);

            unsigned int GetNumberOfPlayers();
            std::string GetPlayerUUID(std::string playerName);

            bool CreatePlayer(std::string playerName);
            bool DeletePlayer(std::string playerName);
            void ListPlayers(std::vector<std::string> &players);
            bool PlayerExists(std::string playerName);

        private:
            std::unique_ptr<UnitManager> unitManager;

            const std::string NumberPlayersKey = "PlayerManager:NumberPlayers";
            const std::string playerListKey = "PlayerManager:PlayerList";
            const std::string playerNameKey = "PlayerManager:PlayerName";

            void IncrementNumberOfPlayers();
            void DecrementNumberOfPlayers();
    };
}