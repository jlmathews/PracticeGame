#include "path.h"
#include "spdlog/spdlog.h"

#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX

namespace PGame
{
    /**
     * Get the current directory of the executable generated.
     * 
     * @param   path is a refernce to be populated with the directory.
     * @returns true if successfully got the directory. false otherwise.
     */
    bool Path::GetCurrentDirectory(std::string &path)
    {
        char result[PATH_MAX];
        ssize_t count = readlink("/proc/self/exe", result, PATH_MAX);

        if (count != -1) {
            path = dirname(result);
            return true;
        }
        else
        {
            spdlog::error("Could not get current directory");
            return false;
        }
    }

    /**
     * Append two directories.
     * If the first path is empty or the second path is empty, then the path will not be modified.
     * 
     * @param   path1 is the first part of the path. path2 is appended to this path.
     * @param   path2 second part of the path.
     */
    void Path::Append(std::string &path1, const std::string path2)
    {
        if("" != path2)
        {
            path1.append("/");
            path1.append(path2);
        }
    }
}
