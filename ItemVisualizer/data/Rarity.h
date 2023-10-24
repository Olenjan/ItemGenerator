#pragma once

#include "BaseData.h"

enum class ERarity
{
    UNKNOWN = 0,
    NORMAL = 1,
    MAGIC = 2,
    RARE = 3,
    UNIQUE = 4
};

static inline std::string toString(ERarity rarity)
{
    switch(rarity)
    {
    case ERarity::NORMAL: return "normal";
    case ERarity::MAGIC:  return "magic";
    case ERarity::RARE:   return "rare";
    case ERarity::UNIQUE: return "unique";
    default:              return "unknown";
    }
}

template <>
inline ERarity fromString<ERarity>(const std::string& str)
{
    if(str == "normal") return ERarity::NORMAL;
    if(str == "magic")  return ERarity::MAGIC;
    if(str == "rare")   return ERarity::RARE;
    if(str == "unique") return ERarity::UNIQUE;

    return ERarity::UNKNOWN;
}
