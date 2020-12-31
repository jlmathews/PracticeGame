
#include "beast.h"
#include "position.h"
#include "unit.h"

#include "spdlog/spdlog.h"

using namespace PGame;

int main()
{
    Beast beast;
    Position* position;

    spdlog::info("Start main.");

    position = beast.GetPosition();
    position->Print();
    beast.Move(1, 5);
    beast.Move(3, 2);
    position->Print();

    return 0;
}
