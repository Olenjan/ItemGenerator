#ifndef AFFIXTYPEFILTER_H
#define AFFIXTYPEFILTER_H

#include "AffixFilterInterface.h"
#include "../../data/AffixType.h"

class AffixTypeFilter: public AffixFilterInterface
{
private:
    std::vector<EAffixType> m_Types;

public:
    AffixTypeFilter(EAffixType type)
        :   m_Types({type})
    {

    }
    AffixTypeFilter(const std::vector<EAffixType>& types)
        :   m_Types(types)
    {
    }

    /*
        //Todo testing required:
        AffixRoll[0] = Implicit
        AffixRoll[1] = Prefix
        AffixRoll[2] = Suffix

        Any of [Implicit]:
            Accepts: [0]

        Any of [Implicit, Prefix]:
            Accepts: [0], [1]

        All of [Suffix]:
            Accepts: [2]

        All of [Implicit, Prefix, Suffix]:
            Accepts: [0], [1], [2]
    */
    virtual bool acceptAffixRoll(const RandomStateAffix& affixRoll) const override
    {
        return std::any_of(m_Types.begin(), m_Types.end(), [affixRoll](const EAffixType& affixType){ return affixRoll.affixType == affixType;});
    }
};


#endif // AFFIXTYPEFILTER_H
