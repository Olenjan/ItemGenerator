#ifndef AFFIXROLL_H
#define AFFIXROLL_H

#include <functional>

#include "BaseData.h"

#include "AffixRollEffetType.h"
#include "AffixTag.h"
#include "AffixType.h"

#include "Modifier.h"

struct MinMaxRoll
{
    RollValue min;
    RollValue max;
};

struct ModifierRoll
{
    EAffixRollEffectType effectType;    // (numeric mod)

    MinMaxRoll minMax;

    Modifier* modifier;
};

struct AffixRoll;
struct RolledModifier
{
    const AffixRoll* roll;
    std::vector<RollValue> values;

    const std::string getRolledName(int numMod) const;

    const std::vector<std::string> getRolledNames() const;
};

class ConstrainRangeBase
{
public:
    ConstrainRangeBase() = default;

    virtual MinMaxRoll call(const RolledModifier& rollsSoFar, const ModifierRoll& currentModRolls, int modRollID) = 0;
};

inline const char ROLL_NUMBER_WILDCARD = '#';
struct AffixRoll
{
    TableID id;

    Name name;                          // (# to Strength) when 1 ModifierRoll
                                        // (Adds # to # Physical Damage) when 2 ModifierRoll
                                        // (# to Maximum Life;# to Maximum Stamina) when 2 ModifierRoll

    NameTag nameTag;                    // (suffix_x_to_strength) '_' separated nametag
                                        // (prefix_flat_x_to_x_physical_damage) '_' separated nametag
                                        // (prefix_x_increase_physical_damage) '_' separated nametag
                                        //# to Maximum Life;# to Maximum Stamina


    std::vector<ModifierRoll> modRolls;

    Level level;

    EAffixType affixType;               // (Suffix)
    Name itemName;                      // (of Something) Name contributed to item
    std::vector<EAffixTag> tags;

    ConstrainRangeBase* rangeConstraint = nullptr;
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
    virtual MinMaxRoll call(const RolledModifier& rollsSoFar, const ModifierRoll& currentModRolls, int modRollID)
    {
        auto newMin = currentModRolls.minMax.min;
        if(modRollID == 1 && rollsSoFar.values[0] > newMin)
        {
            newMin = rollsSoFar.values[0];
        }

        return MinMaxRoll{newMin, currentModRolls.minMax.max};
    };
};

#endif
