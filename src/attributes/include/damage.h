#pragma once

#include <map>

namespace PGame
{
    enum class DamageType_e
    {
        PHYSICAL,
        FIRE,
        ICE,
        LIGHTNING,
        BLEEDING,
    };

    typedef struct
    {
        int damage;
        int percentage;
    } DamageAttribute_t;

    class Damage
    {
        public:
            Damage();

            void AddDamage(DamageType_e damageType, int damage, int percentage);
            void AddDamage(DamageType_e damageType, DamageAttribute_t attrib);
            void UpdateDamage(DamageType_e damageType, DamageAttribute_t attrib);

            void Print();

        private:
            std::map<DamageType_e, DamageAttribute_t> damageAttributes;
    };
}