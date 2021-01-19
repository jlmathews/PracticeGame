#include <string>

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include "lua_wrapper.h"
#include "path.h"
#include "spdlog/spdlog.h"

#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX

using namespace PGame;

void createTable(sol::state &lua)
{
    lua.script(R"(
		data = {
            name = "attack",
            dmg = 5,
            speed = 1.2
        }
	)");

    sol::table data = lua["data"];
    std::string name = lua["data"]["name"];
    int damage = data["dmg"];
    float speed = data["speed"];

    spdlog::info("Name: {}, DMG: {}, Speed: {}", name, damage, speed);

    lua.script("function f (d) return (d.dmg * d.speed) end");
    lua.script("output = f(data)");
    float output = lua["output"];
    spdlog::info("DPS: {}", output);
}

void createTableLuaWrapper()
{
    LuaWrapper lua;

    spdlog::info("Run Create Table LUA Wrapper");

    lua.RunCommand(R"(
		data = {
            name = "attack",
            dmg = 5,
            speed = 1.2
        }
	)");

    auto data = lua["data"];
    std::string name = lua["data"]["name"];
    int damage = data["dmg"];
    float speed = data["speed"];

    spdlog::info("Name: {}, DMG: {}, Speed: {}", name, damage, speed);

    lua.RunCommand("function f (d) return (d.dmg * d.speed) end");
    std::string resultName = "output";
    lua.RunCommand(resultName + " = f(data)");
    float output = lua[resultName];
    spdlog::info("DPS: {}", output);
}

void loadScript(sol::state &lua, std::string filename)
{
    std::string path;

    Path::GetCurrentDirectory(path);
    Path::Append(path, filename);

    spdlog::info("Lua File: {}", path);
    lua.script_file(path);
}

void appendLuaPath(sol::state &lua, std::string path)
{
    std::string str = "package.path = package.path..';" + path + "/?.lua'";
    spdlog::info("Package path: {}", str);
    lua.script("package.path = package.path..';" + path + "/?.lua'");
}

void battle()
{
    LuaWrapper lua;

    lua.AppendCurrentPath();

    lua.LoadScript("rogue.lua");
    lua.LoadScript("attack.lua");

    spdlog::info("Create rogue.");
    lua.RunCommand("rogue1 = Rogue:new()");

    spdlog::info("Set primary weapon to bow.");
    lua.RunCommand("rogue1.player:setPrimaryWeapon(bow)");

    sol::table weapon = lua["bow"];
    std::string name = weapon["name"];
    int damage = weapon["max_dmg"];
    float speed = weapon["speed"];

    while(true)
    {
        spdlog::info("Player1 attack!");
        lua.RunCommand("rogue1.player:attack(enemy1)");

        std::string enemy_name = lua["enemy1"]["name"];
        float enemy_hp = lua["enemy1"]["hp"];

        if(enemy_hp < 0)
        {
            spdlog::info("Enemy {} defeated!", enemy_name);
            lua.RunCommand("earned_exp = enemy1:getExperience()");
            int earned_exp = lua["earned_exp"];
            spdlog::info("Earned Exp. {}", earned_exp);
            break;
        }

        spdlog::info("Enemy attack!");
        lua.RunCommand("attack(enemy1, club, rogue1)");

        std::string rogue_name = lua["rogue1"]["name"];
        float rogue_hp = lua["rogue1"]["hp"];

        if(rogue_hp <= 0)
        {
            spdlog::info("Lost battle to {}!", enemy_name);
            break;
        }

        spdlog::info("Weapon: {}, Max DMG: {}, Speed: {}", name, damage, speed);
        spdlog::info("Player: {}, HP: {}", rogue_name, rogue_hp);
        spdlog::info("Enemy: {}, HP: {}", enemy_name, enemy_hp);
    }
}

int main() {
	sol::state lua;

    spdlog::set_level(spdlog::level::debug);

    spdlog::info("Practice sol2.");

	lua.open_libraries(sol::lib::base);

    lua.script("print('Test LUA')");

    createTable(lua);
    createTableLuaWrapper();
    battle();

	return 0;
}
