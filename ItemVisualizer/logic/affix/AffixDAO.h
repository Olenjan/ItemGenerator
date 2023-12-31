#ifndef AFFIXDAO_H
#define AFFIXDAO_H

#include "AffixFilterInterface.h"
#include "../../data/RollDatabase.h"

#include "AffixTypeFilter.h"
#include "AffixTagsFilter.h"
#include "AffixNameFilter.h"
#include "AffixNameTagFilter.h"

#include "AffixLevelFilter.h"
#include "AffixTierFilter.h"
#include "AffixModCountFilter.h"
#include "AffixNameTagDuplicationFilter.h"

class AffixDataAccessObject
{
private:
    std::shared_ptr<RollDatabase> m_Database;
    std::vector<std::shared_ptr<AffixFilterInterface>> m_Filters; // Owned filters

public:
    AffixDataAccessObject(std::shared_ptr<RollDatabase> database)
        :   m_Database(std::move(database))
    {

    }

    AffixDataAccessObject& addFilter(std::shared_ptr<AffixFilterInterface> filter)
    {
        m_Filters.emplace_back(std::move(filter));

        return *this;
    }

    size_t filterSize() const
    {
        return m_Filters.size();
    }

    void clearFilter()
    {
        m_Filters.clear();
    }

    //todo: remove AffixRoll* raw
    std::vector<const RandomStateAffix*> getFilteredAffixRolls() const
    {
        std::vector<const RandomStateAffix*> result;

        for(const auto& ar: m_Database->affixRolls.getAll())
        {
            bool arAccepted = true;
            for(const auto& f: m_Filters)
            {
                if(f->acceptAffixRoll(ar) == false)
                {
                    arAccepted = false;
                    break;
                }
            }
            if(arAccepted)
                result.push_back(&ar);
        }

        return result;
    };
};

#endif // AFFIXDAO_H
