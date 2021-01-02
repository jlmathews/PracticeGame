#pragma once

#include <string>
#include <memory>

#include <sw/redis++/redis++.h>

using namespace sw::redis;

namespace PGame
{
    class UnitManager
    {
        public:
            UnitManager();

            unsigned int GetNumberOfPlayers();
            std::string GetPlayerUuid(std::string playerName);
            bool CreatePlayer(std::string playerName);
            bool DeletePlayer(std::string playerName);

            void Reset();

        private:
            std::unique_ptr<Redis> redis;
            const std::string NumberPlayersKey = "UnitManager:NumberPlayers";
            const std::string playerListKey = "UnitManager:PlayerList";
            const std::string playerNameKey = "name";

            void IncrementNumberOfPlayers();
            void DecrementNumberOfPlayers();
    };
}
