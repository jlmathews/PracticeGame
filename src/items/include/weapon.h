#pragma once

#include "damage.h"
#include "item.h"

namespace PGame
{
    class Weapon: public Item
    {
        public:
            Weapon();
        private:
            Damage damage;
    };
}