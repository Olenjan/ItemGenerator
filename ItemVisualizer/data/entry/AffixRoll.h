#ifndef AFFIXROLL_H
#define AFFIXROLL_H

#include <functional>

#include "DataTableBase.h"

#include "../AffixRollEffetType.h"
#include "../AffixTag.h"
#include "../AffixType.h"

#include "../collapsed/CollapsedAffix.h"

#include "Modifier.h"

// Best solution:

//PossibleX are objects that are a

struct AffixMinMaxRoll
{
    RollValue min;
    RollValue max;
};

struct RandomStateAffixModifier
{
    EAffixRollEffectType effectType;    // (numeric mod)

    AffixMinMaxRoll minMax;

    const Modifier* modifier;
};

class ConstrainRangeBase
{
public:
    ConstrainRangeBase() = default;

    virtual AffixMinMaxRoll call(const CollapsedAffix& rollsSoFar, const RandomStateAffixModifier& currentModRolls, int modRollID) = 0;
};

inline const char ROLL_NUMBER_WILDCARD = '#';

//todo: Tier ?
struct RandomStateAffix
{
    TableID id;
    EAffixTier tier;

    Name name;                          // Must have Equal number of # to modRolls array size
                                        // (# to Strength) when 1 ModifierRoll
                                        // (Adds # to # Physical Damage) when 2 ModifierRoll
                                        // (# to Maximum Life;# to Maximum Stamina) when 2 ModifierRoll

    NameTag nameTag;                    // (suffix_x_to_strength) '_' separated nametag
                                        // (prefix_flat_x_to_x_physical_damage) '_' separated nametag
                                        // (prefix_x_increase_physical_damage) '_' separated nametag
                                        //# to Maximum Life;# to Maximum Stamina

    std::vector<RandomStateAffixModifier> modifierRolls; // One affix can have multiple rolls affecting different

    Level level;

    EAffixType affixType;               // (Suffix)
    Name itemName = "";                 // (of Something) Name contributed to item
    std::vector<EAffixTag> tags;

    ConstrainRangeBase* rangeConstraint = nullptr;

    bool validate() const
    {
        int nameWildcardCount = std::count_if( name.begin(), name.end(), []( char c ){return c =='#';});
        int modRollsCount = modifierRolls.size();
        return nameWildcardCount == modRollsCount;
    }

    //Returns wildcard filled name with (min - max) values from AffixModifierRoll
    std::string getRangeRollName() const
    {
        std::string result = name;

        for(size_t i = 0; i < modifierRolls.size(); i++)
        {
            size_t foundWildcardPosition = result.find(ROLL_NUMBER_WILDCARD);
            if (foundWildcardPosition == std::string::npos)
            {
                throw std::runtime_error("RolledModifier::getRolledName Does not have enough wildcards");
                break;
            }

            auto minMax = modifierRolls[i].minMax;
            std::string replacementStr = "(" + std::to_string(minMax.min) + " - " + std::to_string(minMax.max) + ")";
            result.replace(foundWildcardPosition, 1, replacementStr);
        }

        return result;
    }

};

//Constraints

//Roll 0 is taken as min value for Roll 1
//Mainly intended for 'Adds x to y ..."
class ConstrainRange_roll_0_rng_1_min: public ConstrainRangeBase
{
public:
    ConstrainRange_roll_0_rng_1_min() = default;

    //  rollsSoFar - Rolled RNG cache
    //  currentModRolls - Current mod being rolled
    //  modRollID - number n of mod being rolled; modRollID - 1 = previous mod when modRollID > 0
    virtual AffixMinMaxRoll call(const CollapsedAffix& rollsSoFar, const RandomStateAffixModifier& currentModRolls, int modRollID)
    {
        auto newMin = currentModRolls.minMax.min;
        if(modRollID == 1 && rollsSoFar.values[0] > newMin)
        {
            newMin = rollsSoFar.values[0];
        }

        return AffixMinMaxRoll{newMin, currentModRolls.minMax.max};
    };
};

#endif
