#include "lua_wrapper.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(LuaWrapper_Create, LuaWrapper_Create1)
{
    LuaWrapper luaWrapper;
}

TEST(LuaWrapper_LoadScript, LuaWrapper_LoadScript_InvalidScript)
{
    LuaWrapper luaWrapper;

    ASSERT_EQ(false, luaWrapper.LoadScript("test.lua"));
}

TEST(LuaWrapper_LoadScript, LuaWrapper_LoadScript_Found)
{
    LuaWrapper luaWrapper;
    luaWrapper.AppendCurrentPath();

    ASSERT_EQ(true, luaWrapper.LoadScript("test.lua"));
}

TEST(LuaWrapper_RunCommand, LuaWrapper_RunCommand_CreateVar)
{
    LuaWrapper luaWrapper;
    luaWrapper.RunCommand("test = 123");

    ASSERT_EQ(123, luaWrapper["test"]);
}
