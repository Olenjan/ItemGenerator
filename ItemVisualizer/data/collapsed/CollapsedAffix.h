#ifndef COLLAPSEDAFFIX_H
#define COLLAPSEDAFFIX_H

#include <vector>
#include "../BaseData.h"

struct PossibleAffix;
struct CollapsedAffix
{
    const PossibleAffix* roll;
    std::vector<RollValue> values;

    const std::string getRolledName() const;
};

#endif // COLLAPSEDAFFIX_H
