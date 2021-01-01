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
            void IncrementNumberOfPlayers();
            void DecrementNumberOfPlayers();

            void CreatePlayer(std::string playerName);

        private:
            std::unique_ptr<Redis> redis;
    };
}
