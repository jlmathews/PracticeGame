#include "character_manager.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    CharacterManager::CharacterManager()
    {
        spdlog::info("Create CharacterManager");
    }

    Character* CharacterManager::CreateCharacter(std::string name, std::string classType)
    {
        Character *character = new Character();

        return character;
    }

    void CharacterManager::DeleteCharacter(std::string name)
    {

    }
}
