#include "AffixRoll.h"

const std::string RolledModifier::getRolledName(int numMod) const
{
    std::string name = roll->name;

    for(size_t i = 0; i < roll->modRolls.size(); i++)
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

const std::vector<std::string> RolledModifier::getRolledNames() const
{
    std::vector<std::string> names;

    auto numWildcards = roll->modRolls.size();
    for(int i = 0; i < numWildcards; i++)
    {
        auto name = getRolledName(i);
        names.push_back(name);
    }

    return names;
}
