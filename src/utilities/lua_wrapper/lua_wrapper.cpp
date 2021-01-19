#include "lua_wrapper.h"
#include "path.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    LuaWrapper::LuaWrapper()
    {
        spdlog::info("{}", __func__);
        lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::package);
    }

    void LuaWrapper::AppendPath(std::string path)
    {
        std::string command = "package.path = package.path..';" + path + "/?.lua'";
        spdlog::debug("Updated Package path: {}", command);
        lua.script(command);
    }

    void LuaWrapper::AppendCurrentPath()
    {
        std::string path = "";
        Path::GetCurrentDirectory(path);

        AppendPath(path);
    }

    bool LuaWrapper::LoadScript(std::string filename)
    {
        std::string path = "";

        Path::GetCurrentDirectory(path);
        Path::Append(path, filename);

        if(!Path::Exists(path))
        {
            spdlog::error("Cannot find script {}", path);
            return false;
        }

        spdlog::debug("Load Lua Script: {}", path);
        lua.script_file(path);

        return true;
    }

    void LuaWrapper::RunCommand(std::string command)
    {
        spdlog::debug("Run command: {}", command);
        lua.script(command);
    }
}
