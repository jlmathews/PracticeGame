#include "lua_wrapper.h"
#include "path.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    LuaWrapper::LuaWrapper()
    {
        spdlog::info("{}", __func__);
        lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::package, sol::lib::table);
    }

    void LuaWrapper::AppendPath(std::string path)
    {
        std::string command;
        pathList.push_back(path);

        command = "package.path = package.path..'";

        for(auto luaPath: pathList)
        {
            command += ";" + path + "/?.lua";
        }

        command += "'";

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
        std::string full_path = "";

        for(auto path: pathList)
        {
            Path::Append(path, filename);
            if(Path::Exists(path))
            {
                full_path = path;
                break;
            }
        }

        if("" == full_path)
        {
            spdlog::error("Cannot find script {}", full_path);
            return false;
        }

        spdlog::debug("Load Lua Script: {}", full_path);
        lua.script_file(full_path);

        return true;
    }

    void LuaWrapper::RunCommand(std::string command)
    {
        spdlog::debug("Run command: {}", command);
        lua.script(command);
    }
}
