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
            static void Append(std::string &path1, const std::string path2);
            static bool CreateDirectory(const std::string path);
            static bool DeleteDirectory(const std::string path);
            static bool Exists(const std::string path);
            static bool GetCurrentDirectory(std::string &path);
            static bool GetRootDirectory(std::string &path);
    };
}
