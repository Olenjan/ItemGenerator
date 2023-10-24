#pragma once

#include "BaseData.h"
#include "ModifierType.h"

struct Modifier
{
    TableID id;
    Name name;
    NameTag nameTag;
    Description description;
    ModifierType type;

};

