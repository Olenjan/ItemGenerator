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
    NameTag nameTag; // unique nametag generated for each drop

    ERarity rarity;
    
    // ? vector of affixes or affixes explicitly
    std::vector<CollapsedAffix> implicit;
    std::vector<CollapsedAffix> prefix;
    std::vector<CollapsedAffix> suffix;

    //todo: implement checking if item is valid
    //  If affixes are where they belong and within roll range
    //  Affix count and rarity match
    //  Base exists
    //  Name is something that makes sense, parts must match affixes
    bool validate() const {return false; };
};

