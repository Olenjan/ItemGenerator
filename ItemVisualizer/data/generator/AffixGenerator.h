#ifndef AFFIXGENERATOR_H
#define AFFIXGENERATOR_H

#include <regex>
#include "RandomNumberGenerator.h"

#include "../database.h"
#include "../AffixType.h"
#include "../AffixRoll.h"
#include "../Rarity.h"

#include "AffixFilter.h"

class CAffixGenerator: public AffixFilter
{
private:
public:
    CAffixGenerator(std::shared_ptr<Database> database)
        :   AffixFilter(std::move(database))
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

        for(const auto& modRoll: result.roll->modifierRolls)
        {
            int roll = RNG(modRoll.minMax.min, modRoll.minMax.max).get();
            result.values.push_back(roll);
        }
        return result;
    }
};

//CAffixGenerator Helps with generating affixes
//Features:
//  Collapses one affix randomly from remaining filtered affixes
//  Performs controlled roll given item.
//Basic filters
//numeric filter -> -1 represents infinite
//CAffixGenerator(database).filter() -> CAffixGenerator*
//CAffixGenerator(database).filter_type( { EAffixType::IMPLICIT, EAffixType::SUFFIX } ).collapse() -> CollapsedAffix
//CAffixGenerator(database).filter_tag_all( { EAffixTag::ATTRIBUTE, EAffixTag::LIFE } ).collapse() -> CollapsedAffix // Must contain all
//CAffixGenerator(database).filter_tag_any( { EAffixTag::ATTRIBUTE, EAffixTag::LIFE } ).collapse() -> CollapsedAffix // Must contain any of
//CAffixGenerator(database).filter_tier(EAffixTier::TIER_10, EAffixTier::TIER_1).collapse() -> CollapsedAffix   //From lower to higher tier
//CAffixGenerator(database).filter_nametag("suffix_x_to_strength_3").collapse() -> CollapsedAffix               //by nametag
//CAffixGenerator(database).filter_name("# to Dexterity").collapse() -> CollapsedAffix                          //by name
//CAffixGenerator(database).filter_level(0, 99).collapse() -> CollapsedAffix                                    //by minimum and maximum level
//CAffixGenerator(database).filter_ModRollCount(-1, -1).collapse() -> CollapsedAffix                            // Usually have just 1 ModRoll per 1 affix, there are exceptions

//chaining filters
//CAffixGenerator(database).filter_nametag_regex("suffix_x_to_strength_*").collapse() -> CollapsedAffix
//CAffixGenerator(database).filter_nametag_regex("suffix_x_to_strength_*").filter_tier(EAffixTier::TIER_10, EAffixTier::TIER_1).collapse() -> CollapsedAffix

//Control roll
//
/*
 * //Generate random affix
class CAffixGenerator
{
private:
    AffixFilter m_AffixFilter;
public:
    CAffixGenerator(std::shared_ptr<Database> database)
        :   m_AffixFilter(std::move(database))
    {
    }

    AffixFilter& getAffixFilter(){return m_AffixFilter;}

    //Rolls values for given AffixRoll
    virtual std::optional<CollapsedAffix> collapse(EAffixType overloadAffixType = EAffixType::NONE)
    {
        m_AffixFilter.clearFilter();

        EAffixType rollType = overloadAffixType;
        if(rollType == EAffixType::NONE)
        {
            rollType = static_cast<EAffixType>(RNG(2, 3).get());
        }
        m_AffixFilter.addFilter(std::make_unique<AffixTypeFilter>(rollType));

        auto possibleAffixRolls = m_AffixFilter.getFilteredAffixRolls();

        if(possibleAffixRolls.size() == 0)
            return {};

        //choose one | todo: weights
        int possibleAffixIndex = RNG(0, possibleAffixRolls.size() - 1).get();


        CollapsedAffix result;
        result.roll = possibleAffixRolls[possibleAffixIndex];

        int i = 0;
        for(const auto& modRoll: result.roll->modifierRolls)
        {
            int roll = RNG(modRoll.minMax.min, modRoll.minMax.max).get();
            result.values.push_back(roll);
            i++;
        }
        return result;
    }

private:
private:
};
*/

#endif // AFFIXGENERATOR_H
