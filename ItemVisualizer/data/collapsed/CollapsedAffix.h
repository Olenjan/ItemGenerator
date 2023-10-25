#ifndef COLLAPSEDAFFIX_H
#define COLLAPSEDAFFIX_H

#include <vector>
#include "../BaseData.h"

struct AffixRoll;
struct CollapsedAffix
{
    const AffixRoll* roll;
    std::vector<RollValue> values;

    const std::string getRolledName() const;
};

#endif // COLLAPSEDAFFIX_H
