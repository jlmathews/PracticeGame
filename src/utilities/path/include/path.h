#pragma once

#include <string>

namespace PGame
{
    /**
     * Path class
     */
    class Path
    {
        public:
            static bool GetCurrentDirectory(std::string &path);
            static void Append(std::string &path1, const std::string path2);
    };
}
