
#include "beast.h"
#include "position.h"
#include "unit.h"

#include "spdlog/spdlog.h"

#include <sw/redis++/redis++.h>

using namespace PGame;
using namespace sw::redis;

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

    auto redis = Redis("tcp://127.0.0.1:6379");
    auto val = redis.get("test");
    if(val)
    {
        spdlog::info("Redis val: {}", val.value());
    }

    return 0;
}
