#include "position.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    Position::Position(int x, int y): p_x(x), p_y(y)
    {
        spdlog::info("Create Position: ({}, {})", x, y);
    }

    void Position::Print()
    {
        spdlog::info("Position: ({}, {})", X(), Y());
    }
}
