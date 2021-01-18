#include "path.h"
#include "gtest/gtest.h"

#include <string>

using namespace PGame;

TEST(Path_GetCurrentDirectory, Path_GetCurrentDirectory1)
{
    std::string path;
    ASSERT_EQ(true, Path::GetCurrentDirectory(path));
}

TEST(Path_GetCurrentDirectory, Path_GetCurrentDirectory2)
{
    std::string path;
    ASSERT_EQ(true, Path::GetCurrentDirectory(path));
    ASSERT_NE("", path);
}

TEST(Path_Append, Path_Append_StrsEmpty)
{
    std::string path1 = "";
    std::string path2 = "";
    Path::Append(path1, path2);
    ASSERT_EQ("", path1);
}

TEST(Path_Append, Path_Append_FirstStrEmpty)
{
    std::string path1 = "";
    std::string path2 = "path";
    Path::Append(path1, path2);
    ASSERT_EQ("/path", path1);
}

TEST(Path_Append, Path_Append_SecondStrEmpty)
{
    std::string path1 = "/test";
    std::string path2 = "";
    Path::Append(path1, path2);
    ASSERT_EQ("/test", path1);
}

TEST(Path_Append, Path_Append_NonEmptyStrings)
{
    std::string path1 = "/test";
    std::string path2 = "path";
    Path::Append(path1, path2);
    ASSERT_EQ("/test/path", path1);
}
