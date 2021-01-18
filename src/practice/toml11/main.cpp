#include <string>

#include "path.h"

#include "spdlog/spdlog.h"
#include <toml.hpp>

using namespace PGame;

void loadTomlFile(toml::basic_value<::toml::discard_comments, std::unordered_map, std::vector> &data, std::string filename)
{
    std::string path;

    Path::GetCurrentDirectory(path);
    Path::Append(path, filename);

    spdlog::info("Load TOML File: {}", path);
    data  = toml::parse(path);
}

int main()
{
    spdlog::info("Practice toml11.");

    toml::basic_value<::toml::discard_comments, std::unordered_map, std::vector> data;
    loadTomlFile(data, "test.toml");

    spdlog::info("Parse TOML File");

    const auto debugModeEnabled = toml::find<bool>(data, "Debug", "Enable");

    if(debugModeEnabled)
    {
        spdlog::set_level(spdlog::level::debug);
        spdlog::debug("Debug mode enabled.");
    }
    else
    {
        spdlog::info("Debug mode disabled.");
    }

	return 0;
}
