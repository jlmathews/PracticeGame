#include "unit.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    Unit::Unit()
    {
        spdlog::info("Create Unit");
        position = std::make_unique<Position>(0, 0);
    }

    void Unit::Move(int x, int y)
    {
        position->X(position->X() + x);
        position->Y(position->Y() + y);
    }
}
