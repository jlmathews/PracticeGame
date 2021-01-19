#include "path.h"
#include "spdlog/spdlog.h"

#include <libgen.h>         // dirname
#include <unistd.h>         // readlink
#include <linux/limits.h>   // PATH_MAX

#include <ghc/filesystem.hpp>

namespace fs = ghc::filesystem;

namespace PGame
{
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

    /**
     * Create a directory.
     * 
     * @param   path is the path to the directory to create.
     * @returns true if directory is created. false otherwise.
     */
    bool Path::CreateDirectory(const std::string path)
    {
        return fs::create_directory(path);
    }

    /**
     * Delete selected directory.
     * 
     * @param   path is the path to the directory to delete.
     * @returns true if directory is deleted. false otherwise.
     */
    bool Path::DeleteDirectory(const std::string path)
    {
        return fs::remove(path);
    }

    /**
     * Check if path exists.
     * 
     * @param   path is the path to check.
     * @returns true if path exists. false otherwise.
     */
    bool Path::Exists(const std::string path)
    {
        return fs::exists(path);
    }

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

    bool Path::GetRootDirectory(std::string &path)
    {
        path = fs::current_path();
        return true;
    }
}
