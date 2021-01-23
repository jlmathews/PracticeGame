#pragma once

#include "redis_adapter.h"
#include "storage_interface.h"

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
            std::string GetPlayerUuid(std::string playerName);

            bool CreatePlayer(std::string playerName);
            bool DeletePlayer(std::string playerName);
            void ListPlayers(std::vector<std::string> &players);
            bool PlayerExists(std::string playerName);

        private:
            std::shared_ptr<IStorage<RedisAdapter>> storage;

            std::string keyType = "official";
            const std::string NumberPlayersKey = "PlayerManager:NumberPlayers";
            const std::string playerListKey = "PlayerManager:PlayerList";
            const std::string playerNameKey = "PlayerManager:PlayerName";

            void IncrementNumberOfPlayers();
            void DecrementNumberOfPlayers();

            bool GeneratePlayer(std::string playerName);
    };
}
