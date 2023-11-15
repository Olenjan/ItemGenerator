#ifndef AFFIXNAMETAGDUPLICATIONFILTER_H
#define AFFIXNAMETAGDUPLICATIONFILTER_H

#include "AffixFilterInterface.h"


//Checks nametag and disallows duplicates
class AffixNameTagDuplicationFilter: public AffixFilterInterface
{
private:
    std::vector<NameTag> m_NameTagCache;

public:
    AffixNameTagDuplicationFilter()
    {
    }

    virtual bool acceptAffixRoll(const PossibleAffix& affixRoll) const override
    {
        //Not implemented, i dont wanna make this non-const
        //Need to find a better solution, maybe one comes up during SQL development when we need to change architecture a bit anyway
        return false;
        //m_NameTagCache.push_back();
    }
};


#endif // AFFIXNAMETAGDUPLICATIONFILTER_H
