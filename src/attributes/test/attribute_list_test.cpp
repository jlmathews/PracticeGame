#include "attribute_list.h"
#include "strength.h"

#include "gtest/gtest.h"

using namespace PGame;

TEST(CreateAttributeList, CreateAttributeList1)
{
    AttributeList attributeList;
    Strength str;

    attributeList.Add(AttributeType_e::STRENGTH, &str);

}
