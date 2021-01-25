#include "unit_manager.h"
#include "uuid_generator.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    // UnitManager::UnitManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage)
    UnitManager::UnitManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage, std::string numberUnitsKey,
            std::string unitListKey, std::string unitNameKey)
    {
        spdlog::info("Create UnitManager");
        storage = inputStorage;

        this->numberUnitsKey = numberUnitsKey;
        this->unitListKey = unitListKey;
        this->unitNameKey = unitNameKey;
    }

    /**
     * Get number of units registered with unit manager
     * 
     * @returns number of units
     */
    unsigned int UnitManager::GetNumberOfUnits()
    {
        auto val = storage->GetValue(numberUnitsKey);
        unsigned int numberOfUnits = 0;

        if(val != "")
        {
            spdlog::info("Number of units: {}", val);
            numberOfUnits = std::stoi(val);
        }
        else
        {
            spdlog::warn("Number of units not created yet.");
        }

        return numberOfUnits;
    }

    /**
     * Get UUID of unit from units name
     * 
     * @param   unitName is the unit name
     * @returns Unit UUID as string
     */
    std::string UnitManager::GetUnitUuid(std::string unitName)
    {
        std::vector<std::string> unitList;
        std::string unitUuid;

        spdlog::debug("Get Unit UUID: {}", unitName);

        storage->SetMembers(unitListKey, unitList);

        for(auto tempUnitUuid: unitList)
        {
            spdlog::debug("Unit UUID: {}", tempUnitUuid);
            std::string tempUnitName;
            storage->HashGet(tempUnitUuid, unitNameKey, tempUnitName);
            if(unitName == tempUnitName)
            {
                spdlog::debug("Found Unit: {}, {}", tempUnitName, tempUnitUuid);
                unitUuid = tempUnitUuid;
                break;
            }
        }

        if(unitUuid == "")
        {
            spdlog::warn("Cannot find unit {}.", unitName);
        }

        return unitUuid;
    }

    /**
     * Increment number of units starting at zero.
     */
    void UnitManager::IncrementNumberOfUnits()
    {
        spdlog::debug("Increment number of units.");

        if(GetNumberOfUnits() == 0)
        {
            storage->SetValue(numberUnitsKey, "1");
        }
        else
        {
            storage->Increment(numberUnitsKey);
        }
    }

    /**
     * Decrement number of units. Number of units can't be less than zero.
     */
    void UnitManager::DecrementNumberOfUnits()
    {
        spdlog::debug("Decrement number of units.");

        if(GetNumberOfUnits() > 0)
        {
            storage->Decrement(numberUnitsKey);
        }
        else
        {
            spdlog::warn("Cannot decrement number of units. Already 0.");
        }
    }

    /**
     * Generate a unit with the specified name and save to storage.
     * 
     * @param   unitName is the unit name
     * @returns true if successfully generated the unit. false otherwise.
     */
    bool UnitManager::GenerateUnit(std::string unitName, std::initializer_list<std::pair<std::string, std::string>> keyValue)
    {
        auto unitUuid = UuidGenerator::GenerateUuid();

        storage->HashSet(unitUuid, keyValue);

        IncrementNumberOfUnits();

        storage->SetAdd(unitListKey, unitUuid);

        return true;
    }

    /**
     * Create a unit with the specified name and save to storage.
     *
     * @param   unitName is the unit name
     * @returns true if successfully created the unit. false otherwise.
     */
    bool UnitManager::CreateUnit(std::string unitName, std::initializer_list<std::pair<std::string, std::string>> keyValue)
    {
        spdlog::debug("Create Unit: {}", unitName);

        // If unit exists, then cannot create unit with same name.
        if(UnitExists(unitName))
        {
            spdlog::warn("Cannot create unit {}. Name already exists.", unitName);
            return false;
        }

        if(!GenerateUnit(unitName, keyValue))
        {
            spdlog::error("Failed to create unit {}.", unitName);
            return false;
        }

        return true;
    }

    /**
     * Delete a unit with the specified name from storage.
     *
     * @param   unitName is the unit name
     * @returns true if successfully deleted the unit. false otherwise.
     */
    bool UnitManager::DeleteUnit(std::string unitName)
    {
        std::string unitUuid;

        spdlog::debug("Delete Unit: {}", unitName);

        if(!UnitExists(unitName))
        {
            spdlog::warn("Cannot delete unit {}.", unitName);
            return false;
        }

        unitUuid = GetUnitUuid(unitName);

        DecrementNumberOfUnits();

        storage->SetRemove(unitListKey, unitUuid);

        return true;
    }

    /**
     * Check if unit exists.
     *
     * @param   unitName is the unit name
     * @returns true if unit exists. false otherwise.
     */
    bool UnitManager::UnitExists(std::string unitName)
    {
        // If empty string is returned, then unit does not exist.
        if("" == GetUnitUuid(unitName))
        {
            return false;
        }

        return true;
    }

    void UnitManager::ListUnits(std::vector<std::string> &units)
    {
        std::vector<std::string> unitList;

        // Get list of unit UUID's
        storage->SetMembers(unitListKey, unitList);

        for(auto tempUnitUuid: unitList)
        {
            std::string tempUnitName;
            storage->HashGet(tempUnitUuid, unitNameKey, tempUnitName);
            spdlog::debug("Unit UUID: {}, Name: {}", tempUnitUuid, tempUnitName);
            units.push_back(tempUnitName);
        }
    }
}