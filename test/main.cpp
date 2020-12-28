#include "gtest/gtest.h"
#include "spdlog/spdlog.h"

int main(int argc, char **argv)
{
    spdlog::info("Start testing.");
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
