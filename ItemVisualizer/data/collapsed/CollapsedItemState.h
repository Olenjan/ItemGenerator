#pragma once

#include <unordered_map>
#include "../BaseData.h"
#include "../ItemBase.h"
#include "../AffixRoll.h"
#include "../Rarity.h"


const int AFFIX_NUM_SUFFIX_MAX = 3;
const int AFFIX_NUM_PREFIX_MAX = 3;
const int AFFIX_NUM_TOTAL_MAX = AFFIX_NUM_SUFFIX_MAX + AFFIX_NUM_PREFIX_MAX;

struct CollapsedItemState
{
    TableID id;
    const ItemBase* base;
    Name name;

    ERarity rarity;
    
    // ? vector of affixes or affixes explicitly
    std::vector<CollapsedAffix> implicit;
    std::vector<CollapsedAffix> prefix;
    std::vector<CollapsedAffix> suffix;
};


