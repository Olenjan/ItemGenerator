#ifndef AFFIXNAMETAGDUPLICATIONFILTER_H
#define AFFIXNAMETAGDUPLICATIONFILTER_H

#include "AffixFilterInterface.h"
#include "../../data/entry/AffixRoll.h"
#include <QDebug>


//Checks nametag and disallows duplicates
class AffixNameTagDuplicationFilter: public AffixFilterInterface
{
private:
    std::vector<NameTag> m_NameTagCache;
public:
    AffixNameTagDuplicationFilter()
    {
    }

    void addNameTag(const NameTag& nameTag){m_NameTagCache.emplace_back(nameTag);}
    void setNameTagCache(const std::vector<NameTag>& nameTagCache){m_NameTagCache = nameTagCache;}
    void clearNameTagCache(){m_NameTagCache.clear();}

    virtual bool acceptAffixRoll(const RandomStateAffix& affixRoll) const override
    {
        bool contains = std::any_of(m_NameTagCache.begin(), m_NameTagCache.end(), [affixRoll](const NameTag& nameTag){
            return affixRoll.nameTag.compare(nameTag) == 0;
        });

        return !contains;
    }
};


#endif // AFFIXNAMETAGDUPLICATIONFILTER_H
