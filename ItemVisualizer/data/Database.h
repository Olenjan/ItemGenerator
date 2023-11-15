#pragma once

#include "BaseData.h"
#include "AffixRoll.h"
#include "ItemBase.h"
#include "collapsed/CollapsedItemState.h"
#include "Modifier.h"

struct Database
{
    CDataTableBase<ItemBase>  itemBases;
    CDataTableBase<Modifier>  modifiers;
    CDataTableBase<PossibleAffix> affixRolls;
    CDataTableBase<CollapsedItemState> uniqueItems;
};
