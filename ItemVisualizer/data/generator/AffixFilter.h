#ifndef AFFIXFILTER_H
#define AFFIXFILTER_H

#include "AffixFilterInterface.h"
#include "../database.h"

#include "AffixTypeFilter.h"
#include "AffixTagsFilter.h"
#include "AffixNameFilter.h"
#include "AffixNameTagFilter.h"

#include "AffixLevelFilter.h"
#include "AffixTierFilter.h"
#include "AffixModCountFilter.h"

class AffixFilter
{
private:
    std::shared_ptr<Database> m_Database;
    std::vector<std::unique_ptr<AffixFilterInterface>> m_Filters; // Owned filters

public:
    AffixFilter(std::shared_ptr<Database> database)
        :   m_Database(std::move(database))
    {

    }

    AffixFilter& addFilter(std::unique_ptr<AffixFilterInterface> filter)
    {
        m_Filters.emplace_back(std::move(filter));

        return *this;
    }

    size_t filterSize() const
    {
        return m_Filters.size();
    }

    void clear()
    {
        m_Filters.clear();
    }

    //
    std::vector<AffixRoll> getFilteredAffixRolls() const
    {
        std::vector<AffixRoll> result;

        for(const auto& ar: m_Database->affixRolls.getAll())
        {
            bool arAccepted = true;
            for(const auto& f: m_Filters)
            {
                if(!f->acceptAffixRoll(ar))
                    arAccepted = false;
            }
            if(arAccepted)
                result.push_back(ar);
        }

        return result;
    };

    //
    virtual CollapsedAffix collapse() const = 0;
};

#endif // AFFIXFILTER_H
