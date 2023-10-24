#ifndef AFFIXTAG_H
#define AFFIXTAG_H

#include "BaseData.h"

enum class EAffixTag
{
    UNKNOWN     = 0,
    ATTRIBUTE   = 1,
    RESOURCE    = 2,
    ELEMENTAL   = 3,
    PHYSICAL    = 4,
    COLD        = 5,
    FIRE        = 6,
    LIGHTNING   = 7,
    DEFENCE     = 8,
    LIFE        = 9,
    MANA        = 10,
    STAMINA     = 11
};

static inline std::string toString(EAffixTag tag)
{
    switch(tag)
    {
    case EAffixTag::ATTRIBUTE:    return "attribute";
    case EAffixTag::RESOURCE:     return "resource";
    case EAffixTag::ELEMENTAL:    return "elemental";
    case EAffixTag::PHYSICAL:     return "physical";
    case EAffixTag::COLD:         return "cold";
    case EAffixTag::FIRE:         return "fire";
    case EAffixTag::LIGHTNING:    return "lightning";
    case EAffixTag::DEFENCE:      return "defence";
    case EAffixTag::LIFE:         return "life";
    case EAffixTag::MANA:         return "mana";
    case EAffixTag::STAMINA:      return "stamina";
    default:                      return "unknown";
    }
}

template <>
inline EAffixTag fromString<EAffixTag>(const std::string& str)
{
    if(str == "attribute")    return EAffixTag::ATTRIBUTE;
    if(str == "resource")     return EAffixTag::RESOURCE;
    if(str == "elemental")    return EAffixTag::ELEMENTAL;
    if(str == "physical")     return EAffixTag::PHYSICAL;
    if(str == "cold")         return EAffixTag::COLD;
    if(str == "fire")         return EAffixTag::FIRE;
    if(str == "lightning")    return EAffixTag::LIGHTNING;
    if(str == "defence")      return EAffixTag::DEFENCE;
    if(str == "life")         return EAffixTag::LIFE;
    if(str == "mana")         return EAffixTag::MANA;
    if(str == "stamina")         return EAffixTag::STAMINA;

    return EAffixTag::UNKNOWN;
}

#endif
