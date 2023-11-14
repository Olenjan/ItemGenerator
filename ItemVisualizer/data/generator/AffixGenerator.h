#ifndef AFFIXGENERATOR_H
#define AFFIXGENERATOR_H

#include <regex>
#include "RandomNumberGenerator.h"

#include "../database.h"
#include "../AffixType.h"
#include "../AffixRoll.h"
#include "../Rarity.h"

#include "AffixFilter.h"


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




//Generate random affix
class CAffixGenerator: public AffixFilter
{
public:
    CAffixGenerator(std::shared_ptr<Database> database): AffixFilter(std::move(database))
    {
    }


    //Rolls values for given AffixRoll
    virtual CollapsedAffix collapse() const
    {
        auto rollType = collapseAffixType();
        auto affixRoll = collapseAffixRoll(rollType);
        return collapseAffixRoll(affixRoll);
    }

private:

    virtual EAffixType collapseAffixType() const
    {
        int number = RNG(1, 3).getRandomNumber();
        return static_cast<EAffixType>(number);
    }

    virtual const AffixRoll* collapseAffixRoll(EAffixType affixType) const
    {

        return nullptr;
    }


    //Rolls values for given AffixRoll
    virtual CollapsedAffix collapseAffixRoll(const AffixRoll* affixRoll) const
    {
        return CollapsedAffix{};
    }

private:
};

#endif // AFFIXGENERATOR_H
