#ifndef AFFIXTYPE_H
#define AFFIXTYPE_H

#include "BaseData.h"

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
