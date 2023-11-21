#ifndef AFFIXMODCOUNTFILTER_H
#define AFFIXMODCOUNTFILTER_H

#include "AffixFilterInterface.h"
#include "../../data/AffixRoll.h"

//nametags are always lower case, check only regex
class AffixModCountFilter: public AffixFilterInterface
{
private:
    int m_MinValue= -1;
    int m_MaxValue= -1;

public:
    AffixModCountFilter(int minValue = -1, int maxValue= -1)
        :   m_MinValue(minValue),
            m_MaxValue(maxValue)
    {
    }

    virtual bool acceptAffixRoll(const RandomStateAffix& affixRoll) const override
    {
        return (m_MinValue == -1 || affixRoll.modifierRolls.size() >= m_MinValue) && (m_MaxValue == -1 || affixRoll.modifierRolls.size() <= m_MaxValue);
    }
};
\
#endif // AFFIXMODCOUNTFILTER_H
