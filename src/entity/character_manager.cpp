#include "character_manager.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    CharacterManager::CharacterManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage)
    {
        spdlog::info("Create CharacterManager");
        unitManager = std::make_unique<UnitManager>(inputStorage, NumberCharacterKey, CharacterListKey, CharacterNameKey);
    }

    /**
     * Get number of characters registered with unit manager
     * 
     * @returns number of characters
     */
    unsigned int CharacterManager::GetNumberOfCharacters()
    {
        return unitManager->GetNumberOfUnits();
    }

    bool CharacterManager::CreateCharacter(std::string name, std::string classType, bool isMainCharacter)
    {
        std::string tempIsMainCharacter;
        spdlog::debug("Create Character: {}", name);

        // If character exists, then cannot create character with same name.
        if(CharacterExists(name))
        {
            spdlog::warn("Cannot create character {}. Name already exists.", name);
            return false;
        }

        if(isMainCharacter)
        {
            tempIsMainCharacter = "true";
        }
        else
        {
            tempIsMainCharacter = "false";
        }

        return unitManager->CreateUnit(name,
        {
            std::make_pair(CharacterNameKey, name),
            std::make_pair(CharacterTypeKey, classType),
            std::make_pair(CharacterMainKey, tempIsMainCharacter),
        });
    }

    bool CharacterManager::DeleteCharacter(std::string name)
    {
        spdlog::debug("Delete Character: {}", name);
        return unitManager->DeleteUnit(name);
    }

    void CharacterManager::ListCharacters(std::vector<std::string> &characters)
    {
        unitManager->ListUnits(characters);
    }

    bool CharacterManager::CharacterExists(std::string name)
    {
        return unitManager->UnitExists(name);
    }
}