#include "damage.h"

#include "spdlog/spdlog.h"

namespace PGame
{
    std::ostream& operator<<(std::ostream& o, DamageType_e x) {
        return o << std::underlying_type<DamageType_e>::type(x);
    }

    Damage::Damage()
    {
        damageAttributes[DamageType_e::PHYSICAL] = {0, 0};
    }

    void Damage::AddDamage(DamageType_e damageType, int damage, int percentage)
    {
        DamageAttribute_t attrib = {damage, percentage};

        UpdateDamage(damageType, attrib);
    }

    void Damage::AddDamage(DamageType_e damageType, DamageAttribute_t attrib)
    {
        UpdateDamage(damageType, attrib);
    }

    void Damage::UpdateDamage(DamageType_e damageType, DamageAttribute_t attrib)
    {
        damageAttributes[damageType] = attrib;
    }

    void Damage::Print()
    {
        for(auto& [damageType, damage]: damageAttributes)
        {
            spdlog::info("Type: {}, DMG: {}, %: {}", damageType,
                damage.damage, damage.percentage);
        }
    }
}
