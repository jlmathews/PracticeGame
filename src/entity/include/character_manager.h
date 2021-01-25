#pragma once

#include "redis_adapter.h"
#include "storage_interface.h"
#include "unit_manager.h"

#include <memory>
#include <string>

namespace PGame
{
    class CharacterManager
    {
        public:
            CharacterManager(std::shared_ptr<IStorage<RedisAdapter>> inputStorage);

            unsigned int GetNumberOfCharacters();

            bool CreateCharacter(std::string name, std::string classType, bool isMainCharacter);
            bool DeleteCharacter(std::string name);
            void ListCharacters(std::vector<std::string> &characters);
            bool CharacterExists(std::string name);
        private:
            std::unique_ptr<UnitManager> unitManager;

            const std::string NumberCharacterKey = "CharacterManager:NumberCharacters";
            const std::string CharacterListKey = "CharacterManager:CharacterList";
            const std::string CharacterNameKey = "CharacterManager:CharacterName";
            const std::string CharacterTypeKey = "CharacterManager:CharacterType";
            const std::string CharacterMainKey = "CharacterManager:CharacterMain";
    };
}