#ifndef AFFIXLEVELFILTER_H
#define AFFIXLEVELFILTER_H

#include "AffixFilterInterface.h"
#include "../../data/AffixRoll.h"

//nametags are always lower case, check only regex
class AffixLevelFilter: public AffixFilterInterface
{
private:
    int m_MinValue= -1;
    int m_MaxValue= -1;

public:
    AffixLevelFilter(int minValue = -1, int maxValue= -1)
        :   m_MinValue(minValue),
            m_MaxValue(maxValue)
    {
    }

    virtual bool acceptAffixRoll(const RandomStateAffix& affixRoll) const override
    {
        return (m_MinValue == -1 || affixRoll.level >= m_MinValue) && (m_MaxValue == -1 || affixRoll.level <= m_MaxValue);
    }
};
#endif // AFFIXLEVELFILTER_H
