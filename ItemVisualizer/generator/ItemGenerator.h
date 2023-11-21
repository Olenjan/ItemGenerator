#ifndef ITEMGENERATOR_H
#define ITEMGENERATOR_H
#include <QDebug>

#include "../data/RollDatabase.h"
#include "../data/AffixType.h"
#include "../data/entry/AffixRoll.h"
#include "../data/Rarity.h"

#include "../data/collapsed/CollapsedAffix.h"
#include "../data/collapsed/CollapsedItemState.h"

#include "generator/AffixGenerator.h"



//Generate any specific or as restricted ITEM as i want
//Generate any speicifc or as restricted AFFIX as i want
//What if I need:
//      Basic Existing roll restriction
//      (full specific roll): T1, Max Life roll
//      (specific tier from any): T1, Any
//      (specific tier from any <tag>): T1, Any from <tag>

//Test1: Generate Rare with X base, 6 specific fixed value affixes
//Test2: Generate Rare with X base, 1 specific fixed value affixes(T1 Max Life)
//Test3: Generate Rare with X base, 1 specific fixed value affixes(T1 Max Life) and 5 random rolls

//Some object that

//Modify existing item
// Test1: Set rarity to Normal, Magic, Rare, rerolling affixes on empty slots, keeping old ones, or removing if over rarity limit
// Test2: Full reroll item, keeping rarity
// Test3: Set rarity to Normal, Magic, Rare, (?ignoring affixes)
// Test4: Reroll values of 1 random roll for any rarity item
// Test5: Reroll values of all rolls for any rarity item
// more Specific conditional rolls for any rarity item <AffixType, NumAffix, Tags>
//  Test 6.1: reroll any 1 <tag> affix
//  Test 6.2: reroll all <tag> affix
//  Test 6.3: reroll any 1 suffix
//  Test 6.5: reroll any 1 prefix
//  Test 6.6: reroll all prefix
//  Test 6.7: reroll any 1 implicit
//  Test 6.8: reroll all implicit
//  Test 6.9: reroll any 1 <tag> suffix values
//  Test 6.10: reroll all affixes with <tag> affixes
//  Test 6.11: Add 2 Suffixes of <tag>
//  Test 6.12: Reroll any 2 Affixes to Affix with <tag>

/*
 /Modify Existing item
    // Chaos Orb:
    // Rerolls modifiers on a rare item. It can change affixes, values, and the item's rarity.

    // Exalted Orb:
    // Enhances a rare item with a new random affix, while keeping its rarity.

    // Divine Orb:
    // Rerolls the numeric values of the modifiers on an item without altering its rarity.

    // Regal Orb:
    // Upgrades a magic item to a rare item and rerolls the values of one random affix.

    // Vaal Orb:
    // Corrupts an item, which can have various effects, including making it more powerful or destroying it.

    // Mirror of Kalandra:
    // Creates a duplicate of a non-unique item, making it extremely valuable.

    // Orb of Alchemy:
    // Upgrades a normal item to a rare item with random modifiers.

    // Blessed Orb:
    // Rerolls the values of explicit modifiers on a piece of equipment.

    // Orb of Chance:
    // Upgrades a normal item to a random rarity with random modifiers.

    // Fusing Orb:
    // Randomly modifies the links between sockets on an item.

    Fossils 	No X modifiers and others

 */

//Generate new item with restrictions
class CItemGenerator
{

private:
    std::shared_ptr<RollDatabase> m_Database;
public:
    CItemGenerator(std::shared_ptr<RollDatabase> database)
        :   m_Database(std::move(database))
    {
    }

    virtual CollapsedItemState generate() const
    {
        CollapsedItemState newItem;

        //base
        {
            int rngBase = RNG(0, (int)m_Database->itemBases.getAll().size() - 1).get();
            newItem.base = &m_Database->itemBases.getAll().at(rngBase);
        }
        qDebug() << "newItem.base: " << newItem.base;

        //Test1
        {
            //CItemGenerator itemGen;

            newItem.rarity = static_cast<ERarity>(RNG(1, 3).get());
            qDebug() << "newItem.rarity: " << toString(newItem.rarity).c_str();

            int rollsToPerform = 0;
            {
                if(newItem.rarity == ERarity::NORMAL)
                {
                    rollsToPerform = 0;
                }
                else if(newItem.rarity == ERarity::MAGIC)
                {
                    rollsToPerform = RNG(1, 3).get();
                }
                else if(newItem.rarity == ERarity::RARE)
                {
                    rollsToPerform = RNG(3, 6).get();
                }
            }

            qDebug() << "rollsToPerform: " << rollsToPerform;


            std::vector<CollapsedAffix> testAffixes;
            auto duplicateFilter = std::make_shared<AffixNameTagDuplicationFilter>();
            for(int i = 0; i < rollsToPerform; i++)
            {
                CAffixGenerator affixGen(m_Database);

                //Suffix,Prefix filtering
                {
                    std::vector<EAffixType> affixTypeFilters;// = ({EAffixType::PREFIX, EAffixType::SUFFIX});
                    if(newItem.prefix.size() < 3)
                        affixTypeFilters.push_back(EAffixType::PREFIX);

                    if(newItem.suffix.size() < 3)
                        affixTypeFilters.push_back(EAffixType::SUFFIX);

                    affixGen.addFilter(std::make_shared<AffixTypeFilter>(affixTypeFilters));
                    affixGen.addFilter(duplicateFilter);
                }

                //Leave emtpy or roll ?
                {

                }

                //Do other filtering
                {

                }


                CollapsedAffix affix = affixGen.collapse().value();
                duplicateFilter->addNameTag(affix.roll->nameTag);
                testAffixes.push_back(affix);
                qDebug() << "affix: " << affix.getRolledName().c_str();

                //Add collapsed affix to item
                {
                    if(affix.roll->affixType== EAffixType::PREFIX)
                    {
                        newItem.prefix.push_back(affix);
                    }
                    else if(affix.roll->affixType == EAffixType::SUFFIX)
                    {
                        newItem.suffix.push_back(affix);
                    }
                    else
                    {
                        throw std::runtime_error("CItemGenerator::collapse invalid affix type generated");

                    }
                }
            }


            //Test identical
            {
                std::vector<NameTag> nameTags;
                for(auto ta: testAffixes)
                {
                    bool contains = std::any_of(nameTags.begin(), nameTags.end(), [ta](NameTag otherNameTag){
                        return otherNameTag.compare(ta.roll->nameTag) == 0;
                    });

                    if(contains)
                        int i = 0;
                    nameTags.push_back(ta.roll->nameTag);
                }

                int i = 0;

            }


            qDebug() << "Done, generating name";

            //Name
            std::string selectedPrefix = "";
            std::string selectedSuffix = "";

            if(!newItem.prefix.empty() && newItem.prefix.at(0).roll != nullptr)
                selectedPrefix = newItem.prefix.at(0).roll->itemName;
            if(!newItem.suffix.empty() && newItem.suffix.at(0).roll != nullptr)
                selectedSuffix = newItem.suffix.at(0).roll->itemName;

            qDebug() << "newItem.base->name: " << newItem.base->name.c_str();
            qDebug() << "selectedPrefix: " << selectedPrefix.c_str();
            qDebug() << "selectedSuffix: " << selectedSuffix.c_str();


            newItem.name =selectedPrefix + " " + newItem.base->name + " " + selectedSuffix;
            qDebug() << "name: " << newItem.name.c_str();
        }

        return newItem;
    }

private:
    /*
     *     virtual const ItemBase*     rollBase() const = 0;
    virtual ERarity             rollRarity() const = 0;
    virtual int                 rollAffixCount() const = 0;
    virtual EAffixType          rollAffixType() const = 0;

    virtual CollapsedItemState  rollUnique() const = 0;
*/
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
