#ifndef CHARACTER_H
#define CHARACTER_H

#include "BaseData.h"
#include "Modifier.h"


struct CharacterStats
{
    Name name;
    Level level;

    //Resource
    RollValue life  = 0;
    RollValue mana  = 0;
    RollValue stamina = 0;

    //Attr
    RollValue strength = 0;
    RollValue dexterity = 0;
    RollValue intelligence = 0;

    //Offence
    RollValue minimumPhysicalDamage = 0;
    RollValue maximumPhysicalDamage = 0;
    RollValue increasedPhysicalDamage = 0;

    //Defence
    RollValue armor = 0;
};

#endif // CHARACTER_H
