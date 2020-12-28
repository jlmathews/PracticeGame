#pragma once

#include <vector>

namespace PGame
{
    enum class AttributeType_e
    {
        DEXTERITY,
        INTELLIGENCE,
        STRENGTH,
        VITALITY,
    };

    typedef struct
    {
        unsigned int numberOfPoints;
    } Attribute_t;

    class AttributeList
    {
        public:
            AttributeList();

            void Add(Attribute_t attribute);
        private:
            std::vector<Attribute_t> attributes;
    };
}
