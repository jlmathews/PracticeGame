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
    class UnitManager
    {
        public:
            UnitManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage);

            unsigned int GetNumberOfPlayers();
            std::string GetPlayerUuid(std::string playerName);
            bool CreatePlayer(std::string playerName);
            bool DeletePlayer(std::string playerName);

        private:
            std::shared_ptr<IStorage<RedisAdapter>> storage;

            std::string keyType = "official";
            const std::string NumberPlayersKey = "UnitManager:NumberPlayers";
            const std::string playerListKey = "UnitManager:PlayerList";
            const std::string playerNameKey = "UnitManager:PlayerName";

            void IncrementNumberOfPlayers();
            void DecrementNumberOfPlayers();
    };
}
