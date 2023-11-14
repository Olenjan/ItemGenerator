#ifndef AFFIXNAMEFILTER_H
#define AFFIXNAMEFILTER_H

#include <regex>
#include "AffixFilterInterface.h"

class AffixNameFilter: public AffixFilterInterface
{
private:
    Name m_Name;
    EStringFilterType m_StrFilterType;

public:
    AffixNameFilter(const Name& name, const EStringFilterType& strFilterType = EStringFilterType::MATCH_UP)
        :   m_Name(name),
        m_StrFilterType(strFilterType)
    {
    }

    virtual bool acceptAffixRoll(const AffixRoll& affixRoll) const override
    {
        if(m_StrFilterType == EStringFilterType::MATCH_UP)
        {
            return affixRoll.name.compare(m_Name) == 0;
        }
        else if(m_StrFilterType == EStringFilterType::MATCH_LOW)
        {
            Name lowercaseAffixName = affixRoll.name;
            std::transform(lowercaseAffixName.begin(), lowercaseAffixName.end(), lowercaseAffixName.begin(), ::tolower);
            return lowercaseAffixName.compare(m_Name) == 0;
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


#endif // AFFIXNAMEFILTER_H
