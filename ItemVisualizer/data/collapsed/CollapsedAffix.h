#ifndef COLLAPSEDAFFIX_H
#define COLLAPSEDAFFIX_H

#include <vector>
#include "../entry/DataTableBase.h"

struct RandomStateAffix;
struct CollapsedAffix
{
    const RandomStateAffix* roll;
    std::vector<RollValue> values;

    const std::string getRolledName() const;
};

#endif // COLLAPSEDAFFIX_H
