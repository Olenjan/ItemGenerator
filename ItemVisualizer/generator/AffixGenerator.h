#ifndef AFFIXGENERATOR_H
#define AFFIXGENERATOR_H

#include <regex>
#include "RandomNumberGenerator.h"

#include "../data/database.h"
#include "../data/AffixType.h"
#include "../data/AffixRoll.h"
#include "../data/Rarity.h"

#include "../logic/affix/AffixDAO.h"

class CAffixGenerator: public AffixDataAccessObject
{
private:
public:
    CAffixGenerator(std::shared_ptr<Database> database)
        :   AffixDataAccessObject(std::move(database))
    {
    }

    virtual std::optional<CollapsedAffix> collapse()
    {
        auto possibleAffixRolls = getFilteredAffixRolls();

        if(possibleAffixRolls.size() == 0)
            return {};

        //choose one | todo: weights
        int possibleAffixIndex = RNG(0, possibleAffixRolls.size() - 1).get();

        CollapsedAffix result;
        result.roll = possibleAffixRolls[possibleAffixIndex];

        int i = 0;
        for(const auto& modRoll: result.roll->modifierRolls)
        {
            AffixMinMaxRoll minMax = modRoll.minMax;
            if(result.roll->rangeConstraint)
            {
                minMax = result.roll->rangeConstraint->call(result, modRoll, i);
            }

            int roll = RNG(modRoll.minMax.min, modRoll.minMax.max).get();
            result.values.push_back(roll);

            i++;
        }
        return result;
    }
};

#endif // AFFIXGENERATOR_H
