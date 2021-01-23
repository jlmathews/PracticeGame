#pragma once

#include "character.h"

#include <string>

namespace PGame
{
    class CharacterManager
    {
        public:
            CharacterManager();

            Character* CreateCharacter(std::string name, std::string classType);
            void DeleteCharacter(std::string name);
    };
}