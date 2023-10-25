#ifndef ITEMGENERATOR_H
#define ITEMGENERATOR_H

#include "../database.h"
#include "../AffixType.h"
#include "../AffixRoll.h"
#include "../Rarity.h"

#include "../collapsed/CollapsedAffix.h"
#include "../collapsed/CollapsedItemState.h"

class CAffixGenerator
{
public:
protected:
    std::shared_ptr<Database> m_Database;

public:
    CAffixGenerator(std::shared_ptr<Database> database): m_Database(std::move(database))
    {
    }

    virtual const AffixRoll* generateAffix(EAffixType affixType) const
    {
        return nullptr;
    }


    //Rolls values for given AffixRoll
    virtual CollapsedAffix collapseAffix(const AffixRoll* affixRoll) const
    {
        return CollapsedAffix{};
    }

private:
};


class CItemGenerator
{

private:
    std::shared_ptr<Database> m_Database;

    CAffixGenerator m_AffixGen;

public:
    CItemGenerator(std::shared_ptr<Database> database)
        :   m_Database(std::move(database)),
            m_AffixGen(m_Database)
    {
    }

    virtual CollapsedItemState generate() const
    {
        ERarity rarity = rollRarity();
        if(rarity == ERarity::UNIQUE)
            return rollUnique();

        CollapsedItemState item;
        item.rarity = rarity;

        int affixCount = rollAffixCount();
        for(int i = 0; i < affixCount; i++)
        {
            EAffixType affixType = rollAffixType();

            //Roll
            auto affixRoll = m_AffixGen.generateAffix(affixType);
            m_AffixGen.collapseAffix(affixRoll);
        }

        return item;
    }

private:
    virtual ERarity             rollRarity() const = 0;
    virtual int                 rollAffixCount() const = 0;
    virtual EAffixType          rollAffixType() const = 0;
    virtual AffixRoll*          rollAffix(EAffixType affixType) const = 0;


    virtual CollapsedItemState  rollUnique() const = 0;
};



class CDefaultItemGenerator: public CItemGenerator
{
public:
    CDefaultItemGenerator(std::shared_ptr<Database> database)
        :   CItemGenerator(std::move(database))
    {
    }

private:
    virtual ERarity     rollRarity() const
    {
        return ERarity::RARE;
    }

    virtual int         rollAffixCount() const
    {
        return AFFIX_NUM_TOTAL_MAX;
    }

    virtual EAffixType  rollAffixType() const
    {
        return EAffixType::SUFFIX;
    }

    virtual AffixRoll*  rollAffix(EAffixType affixType) const
    {
        return nullptr;
    }

    virtual CollapsedItemState  rollUnique() const
    {
        return CollapsedItemState{};
    }
};

/*
    //do RNG
    {
        Level receiverLevel = 1;
        Level dropLevel = 10;

        //Random base

        auto rngBase = QRandomGenerator::global()->bounded(0, (int)database->itemBases.getAll().size());
        newItem.base = &database->itemBases.getAll()[rngBase];

        //Random rarity
        auto rngRarity = QRandomGenerator::global()->bounded(static_cast<int>(ERarity::NORMAL), static_cast<int>(ERarity::UNIQUE));
        newItem.rarity = static_cast<ERarity>(rngRarity);

        //Random rolls
        if(newItem.rarity == ERarity::UNIQUE)
        {
            //Determine unique
        }
        else
        {
            const int SUFFIX_MAX = 3;
            const int PREFIX_MAX = 3;
            const int AFFIX_MAX = SUFFIX_MAX + PREFIX_MAX;

            //Determine roll count

            std::vector<CollapsedAffix> rolls;
            int suffixCount = 0;
            int prefixCount = 0;

            int rollsToPerform = 0;
            {
                if(newItem.rarity == ERarity::NORMAL)
                {
                    rollsToPerform = 0;
                }
                else if(newItem.rarity == ERarity::MAGIC)
                {
                    rollsToPerform = QRandomGenerator::global()->bounded(1, 3);
                }
                else if(newItem.rarity == ERarity::RARE)
                {
                    rollsToPerform = QRandomGenerator::global()->bounded(3, 6);
                }
            }
            qDebug() << "Rolling " << rollsToPerform << "Affixes";

            for(int i = 0; i < rollsToPerform; i++)
            {
                //Determine Affix type, prefix or suffix
                EAffixType affixType;
                {
                    do
                    {
                        auto rngAffixType = QRandomGenerator::global()->bounded(static_cast<int>(EAffixType::PREFIX), static_cast<int>(EAffixType::SUFFIX) + 1);
                        affixType = static_cast<EAffixType>(rngAffixType);
                    }while((affixType == EAffixType::PREFIX && prefixCount == PREFIX_MAX) || (affixType == EAffixType::SUFFIX && suffixCount == SUFFIX_MAX));
                    qDebug() << "Affix type: " << QString::fromStdString(toString(affixType));
                }

                //Rolls until matches conditions
                //Needs to be optimized
                //Maybe use some kind of filtering ?
                //  To match Tags, ilevel, affixType
                //Filter database for matching stuff, randomly select from one of those ?
                //If filtering results are empty, skip ?
                //database->AffixDataTable.filter(base, tags, ilevel, AffixType)
                const AffixRoll* rolledAffix = nullptr;
                {
                    do{
                        auto rngAffixRoll = QRandomGenerator::global()->bounded(0, (int)database->affixRolls.getAll().size());
                        rolledAffix = &database->affixRolls.getAll()[rngAffixRoll];
                        qDebug() << "Rolli: " << rngAffixRoll << ", " << QString::fromStdString(toString(rolledAffix->affixType));
                    }while(!(rolledAffix->affixType == affixType && rolledAffix->level <= dropLevel));
                    if(affixType == EAffixType::PREFIX)
                        prefixCount++;
                    if(affixType == EAffixType::SUFFIX)
                        suffixCount++;
                    qDebug() << "Rolled Item: " << QString::fromStdString(toString(rolledAffix->affixType)) << ", " << QString::number(rolledAffix->id);
                }
                {

                    CollapsedAffix rolledMod;
                    rolledMod.roll = rolledAffix;

                    int i = 0;
                    for(auto modRoll: rolledAffix->modifierRolls)
                    {
                        AffixMinMaxRoll minMax = modRoll.minMax;
                        if(rolledAffix->rangeConstraint)
                        {
                            minMax = rolledAffix->rangeConstraint->call(rolledMod, modRoll, i);
                        }
                        auto rngValue = QRandomGenerator::global()->bounded((int)minMax.min, (int)minMax.max);
                        rolledMod.values.push_back(rngValue);

                        i++;
                    }

                    rolls.emplace_back(rolledMod);
                }



                qDebug() << "Found " << QString::fromStdString(toString(affixType)) << ": " << rolledAffix->id << "; " << QString::fromStdString(rolledAffix->nameTag);
                qDebug() << "";

            }

            //Set rolls
            for(auto roll: rolls)
            {
                if(roll.roll->affixType == EAffixType::PREFIX)
                {
                    newItem.prefix.push_back(roll);
                }
                else if(roll.roll->affixType == EAffixType::SUFFIX)
                {
                    newItem.suffix.push_back(roll);
                }
            }

            //Name
            std::string selectedPrefix;
            std::string selectedSuffix;

            if(newItem.prefix.size() > 0)
                selectedPrefix = newItem.prefix.at(0).roll->itemName;;
            if(newItem.suffix.size() > 0)
                selectedSuffix = newItem.suffix.at(0).roll->itemName;


            newItem.name = selectedPrefix + " " + newItem.base->name + " " + selectedSuffix;


        }

    }
*/

#endif
