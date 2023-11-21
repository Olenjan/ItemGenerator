#pragma once

#include "DataTableBase.h"
#include "../ItemBaseSlotType.h""

struct ItemBase
{
    TableID id;
    Name name = "";

    NameTag nameTag = "";
    ItemBaseSlotType slot;
};
