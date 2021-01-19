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

TEST(Path_GetRootDirectory, Path_GetRootDirectory)
{
    std::string path;
    ASSERT_EQ(true, Path::GetRootDirectory(path));
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

TEST(Path_CreateDirectory, Path_CreateDirectory_Success)
{
    std::string path = "test_path";
    Path::DeleteDirectory(path);

    ASSERT_EQ(true, Path::CreateDirectory(path));
}

TEST(Path_CreateDirectory, Path_CreateDirectory_MultipleTimes)
{
    std::string path = "test_path";
    ASSERT_EQ(true, Path::DeleteDirectory(path));
    ASSERT_EQ(true, Path::CreateDirectory(path));

    ASSERT_EQ(false, Path::CreateDirectory(path));
}

TEST(Path_Exists, Path_Exists_PathFound)
{
    std::string path = "test_dir";
    Path::CreateDirectory(path);

    ASSERT_EQ(true, Path::Exists(path));
}

TEST(Path_Exists, Path_Exists_PathDeleted)
{
    std::string path = "test_dir";
    Path::CreateDirectory(path);
    ASSERT_EQ(true, Path::Exists(path));

    ASSERT_EQ(true, Path::DeleteDirectory(path));

    ASSERT_EQ(false, Path::Exists(path));
}

TEST(Path_Exists, Path_Exists_InvalidPath)
{
    std::string path = "invalid_test_dir";
    ASSERT_EQ(false, Path::Exists(path));
}
