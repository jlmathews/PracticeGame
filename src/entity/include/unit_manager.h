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
            UnitManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage, std::string numberUnitsKey,
            std::string unitListKey, std::string unitNameKey);

            unsigned int GetNumberOfUnits();
            std::string GetUnitUuid(std::string unitName);

            bool CreateUnit(std::string unitName, std::initializer_list<std::pair<std::string, std::string>> keyValue);
            bool DeleteUnit(std::string unitName);
            void ListUnits(std::vector<std::string> &units);
            bool UnitExists(std::string unitName);

            void IncrementNumberOfUnits();
            void DecrementNumberOfUnits();

        private:
            std::shared_ptr<IStorage<RedisAdapter>> storage;

            std::string numberUnitsKey = "";
            std::string unitListKey = "";
            std::string unitNameKey = "";

            bool GenerateUnit(std::string unitName, std::initializer_list<std::pair<std::string, std::string>> keyValue);
    };
}