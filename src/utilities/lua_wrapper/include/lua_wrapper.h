#pragma once

#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

#include <string>

namespace PGame
{
    class LuaWrapper
    {
        public:
            LuaWrapper();

            bool LoadScript(std::string filename);

            void RunCommand(std::string command);

            void AppendPath(std::string path);
            void AppendCurrentPath();

            auto Get(std::string key)
            {
                return lua[key];
            }

            auto operator[](std::string key)
            {
                return lua[key];
            }

        private:
            sol::state lua;
            std::vector<std::string> pathList;
    };
}

