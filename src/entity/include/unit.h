#pragma once

#include <memory>
#include "position.h"

namespace PGame
{
    class Unit
    {
        public:
            Unit();

            Position* GetPosition() { return position.get(); }

            void Move(int x, int y);

        private:
            std::unique_ptr<Position> position;
    };
}

