#pragma once

#include "entry/DataTableBase.h"
#include "entry/AffixRoll.h"
#include "entry/ItemBase.h"
#include "entry/Modifier.h"
#include "collapsed/CollapsedItemState.h"

struct RollDatabase
{
    CDataTableBase<ItemBase>            itemBases;
    CDataTableBase<Modifier>            modifiers;
    CDataTableBase<RandomStateAffix>    affixRolls;
    CDataTableBase<CollapsedItemState>  uniqueItems;
};
