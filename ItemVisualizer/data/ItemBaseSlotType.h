#pragma once

#include "entry/DataTableBase.h"

enum class ItemBaseSlotType
{
    UNKNOWN     = 0,
    //Equipment
    BODY        = 1,
    HANDS       = 2,
    BELT        = 3,
    RING        = 4,
    AMULET      = 5,
    WEAPON_1H   = 6,
    WEAPON_2H   = 7,
    OFFHAND     = 8,
    HEAD        = 9,
    LEGS        = 10,

    //Misc
    CONSUMABLE  = 11,
    QUEST       = 12
};
