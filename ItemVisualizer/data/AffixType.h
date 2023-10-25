#ifndef AFFIXTYPE_H
#define AFFIXTYPE_H

#include "BaseData.h"


enum class EAffixTier
{
    UNKNOWN = 0,
    TIER_1 = 1,
    TIER_2 = 2,
    TIER_3 = 3,
    TIER_4 = 4,
    TIER_5 = 5,
    TIER_6 = 6,
    TIER_7 = 7,
    TIER_8 = 8,
    TIER_9 = 9,
    TIER_10 = 10,
};

static inline std::string toString(EAffixTier tier)
{
    switch (tier)
    {
    case EAffixTier::TIER_1:   return "TIER_1";
    case EAffixTier::TIER_2:   return "TIER_2";
    case EAffixTier::TIER_3:   return "TIER_3";
    case EAffixTier::TIER_4:   return "TIER_4";
    case EAffixTier::TIER_5:   return "TIER_5";
    case EAffixTier::TIER_6:   return "TIER_6";
    case EAffixTier::TIER_7:   return "TIER_7";
    case EAffixTier::TIER_8:   return "TIER_8";
    case EAffixTier::TIER_9:   return "TIER_9";
    case EAffixTier::TIER_10:  return "TIER_10";
    default:                   return "UNKNOWN";
    }
}

template <>
inline EAffixTier fromString<EAffixTier>(const std::string& str)
{
    if (str == "TIER_1")    return EAffixTier::TIER_1;
    if (str == "TIER_2")    return EAffixTier::TIER_2;
    if (str == "TIER_3")    return EAffixTier::TIER_3;
    if (str == "TIER_4")    return EAffixTier::TIER_4;
    if (str == "TIER_5")    return EAffixTier::TIER_5;
    if (str == "TIER_6")    return EAffixTier::TIER_6;
    if (str == "TIER_7")    return EAffixTier::TIER_7;
    if (str == "TIER_8")    return EAffixTier::TIER_8;
    if (str == "TIER_9")    return EAffixTier::TIER_9;
    if (str == "TIER_10")   return EAffixTier::TIER_10;

    return EAffixTier::UNKNOWN;
}




enum class EAffixType
{
    UNKNOWN  = 0,
    IMPLICIT = 1,
    PREFIX   = 2,
    SUFFIX   = 3,
    UNIQUE   = 4
};

static inline std::string toString(EAffixType type)
{
    switch(type)
    {
    case EAffixType::IMPLICIT:    return "implicit";
    case EAffixType::PREFIX:      return "prefix";
    case EAffixType::SUFFIX:      return "suffix";
    case EAffixType::UNIQUE:      return "unique";
    default:                      return "unknown";
    }
}

template <>
inline EAffixType fromString<EAffixType>(const std::string& str)
{
    if(str == "implicit")    return EAffixType::IMPLICIT;
    if(str == "prefix")      return EAffixType::PREFIX;
    if(str == "suffix")      return EAffixType::SUFFIX;
    if(str == "unique")      return EAffixType::UNIQUE;

    return EAffixType::UNKNOWN;
}

#endif
