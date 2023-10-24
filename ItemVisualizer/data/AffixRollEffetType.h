#ifndef AFFIXROLLEFFECTTYPE_H
#define AFFIXROLLEFFECTTYPE_H

#include "BaseData.h"

enum class EAffixRollEffectType
{
    UNKNOWN,
    NUMBERIC,
    METHOD
};

static inline std::string toString(EAffixRollEffectType type)
{
    switch(type)
    {
    case EAffixRollEffectType::NUMBERIC:     return "numeric";
    case EAffixRollEffectType::METHOD:       return "method";
    default:                                return "unknown";
    }
}

template <>
inline EAffixRollEffectType fromString<EAffixRollEffectType>(const std::string& str)
{
    if(str == "numeric")      return EAffixRollEffectType::NUMBERIC;
    if(str == "method")       return EAffixRollEffectType::METHOD;

    return EAffixRollEffectType::UNKNOWN;
}

#endif
