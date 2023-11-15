#ifndef AFFIXNAMETAGFILTER_H
#define AFFIXNAMETAGFILTER_H

#include <regex>
#include "AffixFilterInterface.h"


//nametags are always lower case, check only regex
class AffixNameTagFilter: public AffixFilterInterface
{
private:
    NameTag m_Name;
    EStringFilterType m_StrFilterType;

public:
    AffixNameTagFilter(const Name& name, const EStringFilterType& strFilterType = EStringFilterType::MATCH_UP)
        :   m_Name(name),
        m_StrFilterType(strFilterType)
    {
    }

    virtual bool acceptAffixRoll(const PossibleAffix& affixRoll) const override
    {
        //nametags are always lower case, check only regex
        if( m_StrFilterType == EStringFilterType::MATCH_UP ||
            m_StrFilterType == EStringFilterType::MATCH_LOW)
        {
            return affixRoll.nameTag.compare(m_Name) == 0;
        }
        else if(m_StrFilterType == EStringFilterType::REGEX)
        {
            try
            {
                std::regex regexPattern(m_Name);
                return std::regex_match(affixRoll.nameTag, regexPattern);
            }
            catch (const std::regex_error&)
            {
                // Handle regex syntax error
                return false;
            }
        }
    }
};


#endif // AFFIXNAMETAGFILTER_H
