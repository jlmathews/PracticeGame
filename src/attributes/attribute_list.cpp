#include "attribute_list.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    AttributeList::AttributeList()
    {
    }

    void AttributeList::Add(Attribute_t attribute)
    {
        attributes.push_back(attribute);
    }
}
