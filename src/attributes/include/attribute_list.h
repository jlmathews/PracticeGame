#pragma once

#include "attribute_types.h"
#include "base_attribute.h"

#include <map>

namespace PGame
{
    class AttributeList
    {
        public:
            AttributeList();

            void Add(AttributeType_e attributeType, BaseAttribute* attribute);
        private:
            std::map<AttributeType_e, BaseAttribute*> attributes;
            std::map<AttributeType_e, unsigned int> data;
    };
}
