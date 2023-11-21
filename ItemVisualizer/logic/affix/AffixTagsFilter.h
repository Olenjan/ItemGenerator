#ifndef AFFIXTAGSFILTER_H
#define AFFIXTAGSFILTER_H

#include "AffixFilterInterface.h"
#include "../../data/AffixTag.h"

class AffixTagsFilter: public AffixFilterInterface
{
private:
    std::vector<EAffixTag>  m_Tags;
    EArrayFilterType        m_ArrayFilterType;

public:
    AffixTagsFilter(std::vector<EAffixTag> tags, const EArrayFilterType& arrayFilterType = EArrayFilterType::ANY)
        :   m_Tags(tags),
        m_ArrayFilterType(arrayFilterType)
    {
    }


    /*
        //Todo testing required:
        AffixRoll[0] = life
        AffixRoll[1] = life, attribute
        AffixRoll[2] = life, attribute, physical
        AffixRoll[3] = life, attribute, physical, cold
        AffixRoll[4] = attribute, physical
        AffixRoll[5] = physical, cold

        Any of [life]:
            Accepts: [0], [1], [2]
            Does not accept: [3], [4], [5], [6]

        Any of [life, attribute]:
            Accepts: [0], [1], [2], [3], [4], [5]
            Does not accept: [6]

        All of [life, attribute]:
            Accepts: [0], [1]
            Does not accept: [2], [3], [4], [5], [6]

        All of [physical, cold]:
            Does not accept: [0], [1], [2], [3], [4], [5], [6]

        None (Always true):
            Accepts all AffixRolls: [0-6]

        Unknown ArrayFilterType (Exception):
            Throws exception
    */
    virtual bool acceptAffixRoll(const RandomStateAffix& affixRoll) const override
    {
        if(m_ArrayFilterType == EArrayFilterType::ANY)
        {
            //Accepts affixRoll if affixRoll.tags contains atleast one item in m_Tags;
            // Loop over m_Tags,
            //  for each tag
            //      accept AffixRoll if affixRoll.tags contains this specific tag
            return std::any_of(m_Tags.begin(), m_Tags.end(), [affixRoll](const EAffixTag& tag){
                return std::any_of(affixRoll.tags.begin(), affixRoll.tags.end(), [tag](const EAffixTag& otherTag){
                    return tag == otherTag;
                });
            });
        }
        else if(m_ArrayFilterType == EArrayFilterType::ALL)
        {
            return std::all_of(m_Tags.begin(), m_Tags.end(), [affixRoll](const EAffixTag& tag){
                return std::all_of(affixRoll.tags.begin(), affixRoll.tags.end(), [tag](const EAffixTag& otherTag){
                    return tag == otherTag;
                });
            });
        }
        else if(m_ArrayFilterType == EArrayFilterType::NONE)
            return true;

        throw std::runtime_error("AffixTypeFilter::acceptAffixRoll(const AffixRoll&): unknown ArrayFilterType");
    }
};

#endif // AFFIXTAGSFILTER_H
