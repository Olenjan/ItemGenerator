#include "CollapsedAffix.h"

// Include in .cpp to avoid compiler warning, .h is included in AffixRolls.h and would cause circular dependency
#include "../entry/AffixRoll.h"

const std::string CollapsedAffix::getRolledName() const
{
    std::string name = roll->name;

    for(size_t i = 0; i < roll->modifierRolls.size(); i++)
    {

        size_t foundWildcardPosition = foundWildcardPosition = name.find(ROLL_NUMBER_WILDCARD);
        if (foundWildcardPosition == std::string::npos)
        {
            throw std::runtime_error("RolledModifier::getRolledName Does not have enough wildcards");
            break;
        }

        const RollValue& val = values[i];
        std::string replacementStr = std::to_string(val);
        name.replace(foundWildcardPosition, 1, replacementStr);
    }
    return name;
}
