#ifndef AFFIXTIERFILTER_H
#define AFFIXTIERFILTER_H

#include "AffixFilterInterface.h"
#include "../AffixType.h"

//nametags are always lower case, check only regex
class AffixTierFilter: public AffixFilterInterface
{
private:
    EAffixTier m_MinValue = EAffixTier::NONE;
    EAffixTier m_MaxValue = EAffixTier::NONE;

public:
    AffixTierFilter(EAffixTier minValue = EAffixTier::NONE, EAffixTier maxValue = EAffixTier::NONE)
        :   m_MinValue(minValue),
            m_MaxValue(maxValue)
    {
    }

    virtual bool acceptAffixRoll(const PossibleAffix& affixRoll) const override
    {
        return (m_MinValue == EAffixTier::NONE || affixRoll.tier >= m_MinValue) && (m_MaxValue == EAffixTier::NONE || affixRoll.tier <= m_MaxValue);
    }
};
\

#endif // AFFIXTIERFILTER_H
