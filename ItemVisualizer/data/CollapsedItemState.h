#pragma once

#include <unordered_map>
#include "BaseData.h"
#include "ItemBase.h"
#include "AffixRoll.h"
#include "Rarity.h"

struct CollapsedItemState
{
    TableID id;
    const ItemBase* base;
    Name name;

    ERarity rarity;

    std::vector<RolledModifier> implicit;
    std::vector<RolledModifier> prefix;
    std::vector<RolledModifier> suffix;
};
