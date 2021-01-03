#include "attribute_list.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    AttributeList::AttributeList()
    {
    }

    void AttributeList::Add(AttributeType_e attributeType, BaseAttribute* attribute)
    {
        attributes[attributeType] = attribute;
    }
}
