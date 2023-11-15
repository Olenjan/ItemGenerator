#ifndef AFFIXFILTERINTERFACE_H
#define AFFIXFILTERINTERFACE_H

#include <stdint.h>
#include "../AffixRoll.h"

class AffixFilterInterface
{
public:
    enum class EArrayFilterType: uint8_t
    {
        NONE,
        ALL, // Checked array must contain any all of the items
        ANY // Checked array must contain any one item
    };

    enum class EStringFilterType: uint8_t
    {
        NONE,
        MATCH_UP, // Uppercase
        MATCH_LOW, //lowercase
        REGEX
    };

public:
    AffixFilterInterface() = default;

    virtual bool acceptAffixRoll(const PossibleAffix& affixRoll) const = 0;
};


#endif // AFFIXFILTERINTERFACE_H
