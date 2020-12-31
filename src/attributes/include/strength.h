#pragma once

#include "attribute.h"

#include <map>

namespace PGame
{
    typedef struct
    {
        unsigned int numberOfPoints;
    } StrengthAttribute_t;

    class Strength: public Attribute
    {
        public:
            Strength();
    };
}
