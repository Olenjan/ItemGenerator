#pragma once

#include "DataTableBase.h"
#include "../ModifierType.h"

struct Modifier
{
    TableID id;
    Name name;
    NameTag nameTag;
    Description description;
    ModifierType type;
};
