#ifndef AFFIXNAMETAGDUPLICATIONFILTER_H
#define AFFIXNAMETAGDUPLICATIONFILTER_H

#include "AffixFilterInterface.h"
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

    virtual bool acceptAffixRoll(const PossibleAffix& affixRoll) const override
    {
        for(const auto& nameTag: m_NameTagCache)
        {
            //qDebug() << "Test " << acceptedAffix->nameTag.c_str() << " vs " << affixRoll.nameTag.c_str();
            if(nameTag.compare(affixRoll.nameTag) == 0)
            {

                qDebug() << "Declined: " << affixRoll.nameTag.c_str();
                return false;
            }
        }
        qDebug() << "Accept: " << affixRoll.nameTag.c_str();

        return true;
    }
    /*
        bool contains = std::any_of(m_NameTagCache.begin(), m_NameTagCache.end(), [affixRoll](const NameTag& nameTag){
            return .compare(affixRoll.nameTag) == 0;
        });

        return !contains;
    }
    */
};


#endif // AFFIXNAMETAGDUPLICATIONFILTER_H
