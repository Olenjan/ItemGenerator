#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Item bases
    {
        //Light
        database.itemBases.add(ItemBase{1, "Cloth Tunic", "body_cloth_tunic_1", ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{2, "Silk Robe", "body_silk_robe_1", ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{3, "Padded Vest", "body_padded_vest_1", ItemBaseSlotType::BODY});
        //Medium
        database.itemBases.add(ItemBase{4, "Leather Jerkin",  "body_leather_jerkin_1",     ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{5, "Studded Leather", "body_studded_leather_1", ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{6, "Scale Armor", "body_scale_armor_1", ItemBaseSlotType::BODY});
        //Heavy
        database.itemBases.add(ItemBase{7, "Chainmail"     ,  "body_chainmail_1",          ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{8, "Full Chainmail", "body_full_chainmail_1", ItemBaseSlotType::BODY});
        database.itemBases.add(ItemBase{9, "Plate Armor", "body_plate_armor_1", ItemBaseSlotType::BODY});
    }

    //Modifiers
    {
        database.modifiers.add(Modifier{1, "Strength",        "mod_strength",     "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{2, "Dexterity",       "mod_dexterity",    "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{3, "Intelligence",    "mod_intelligence", "...", ModifierType::STATIC});

        database.modifiers.add(Modifier{4, "Maximum Life",    "mod_max_life",    "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{5, "Maximum Mana",    "mod_max_mana",    "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{6, "Maximum Stamina", "mod_max_stamina", "...", ModifierType::STATIC});

        database.modifiers.add(Modifier{7, "Minimum Physical Damage", "mod_min_physical_damage", "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{8, "Maximum Physical Damage", "mod_max_physical_damage", "...", ModifierType::STATIC});
        database.modifiers.add(Modifier{9, "Increase Physical Damage", "mod_increase_physical_damage", "...", ModifierType::STATIC});
    }


    //Affix rolls
    {
        //Prefix
        {
            Modifier* modLife = database.modifiers.get("mod_max_life");
            Modifier* modMana = database.modifiers.get("mod_max_mana");
            Modifier* modStamina = database.modifiers.get("mod_max_stamina");

            database.affixRolls.add(AffixRoll{10, "# to Maximum Life",    "prefix_to_max_life_1",       {{EAffixRollEffectType::NUMBERIC, 1, 10,  modLife}}, (Level)1, EAffixType::PREFIX, "Vital", {EAffixTag::LIFE, EAffixTag::RESOURCE}});
            database.affixRolls.add(AffixRoll{11, "# to Maximum Mana",    "prefix_to_max_mana_1",       {{EAffixRollEffectType::NUMBERIC, 1, 10,  modMana}}, (Level)1, EAffixType::PREFIX, "Mystic's", {EAffixTag::MANA, EAffixTag::RESOURCE}});
            database.affixRolls.add(AffixRoll{12, "# to Maximum Stamina", "prefix_to_max_stamina_1",    {{EAffixRollEffectType::NUMBERIC, 1, 10,  modStamina}}, (Level)1, EAffixType::PREFIX, "Breezy", {EAffixTag::MANA, EAffixTag::RESOURCE}});

            database.affixRolls.add(AffixRoll{13, "# to Maximum Life;# to Maximum Stamina", "prefix_x_to_max_life_x_to_stamina", {{EAffixRollEffectType::NUMBERIC, 1, 10,  modLife},
                                                                                                                                  {EAffixRollEffectType::NUMBERIC, 1, 10,  modStamina}}, (Level)1, EAffixType::PREFIX, "Sprout's", {EAffixTag::LIFE, EAffixTag::RESOURCE, EAffixTag::STAMINA}});


            Modifier* modMinPhysicalDamage = database.modifiers.get("mod_min_physical_damage");
            Modifier* modMaxPhysicalDamage = database.modifiers.get("mod_max_physical_damage");
            Modifier* modIncreasePhysicalDamage = database.modifiers.get("mod_increase_physical_damage");

            //There is a roll overlap, we need to solve this via constraints
            //Add constraint method to this roll that makes sure that modRoll[0] value > modRoll[1] min random value
            database.affixRolls.add(AffixRoll{14, "Adds # to # Physical Damage", "prefix_flat_physical_damage_1", {{EAffixRollEffectType::NUMBERIC, 1, 7,  modMinPhysicalDamage},
                                                                                                                   {EAffixRollEffectType::NUMBERIC, 4, 10,  modMaxPhysicalDamage}}, (Level)1, EAffixType::PREFIX, "Brutal", {EAffixTag::PHYSICAL}, new ConstrainRange_roll_0_rng_1_min()});

            database.affixRolls.add(AffixRoll{15, "#% to Physical Damage", "prefix_pct_physical_damage_1", {{EAffixRollEffectType::NUMBERIC, 1, 10,  modIncreasePhysicalDamage}}, (Level)1, EAffixType::PREFIX, "Brutal", {EAffixTag::PHYSICAL}});
        }

        //Suffix
        {
            Modifier* modStrength = database.modifiers.get("mod_strength");
            database.affixRolls.add(AffixRoll{1, "# to Strength", "suffix_x_to_strength_1", {{EAffixRollEffectType::NUMBERIC, 1, 10,  modStrength}}, (Level)1, EAffixType::SUFFIX, "of Might", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{2, "# to Strength", "suffix_x_to_strength_2", {{EAffixRollEffectType::NUMBERIC, 8, 18,  modStrength}}, (Level)8, EAffixType::SUFFIX, "of Power", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{3, "# to Strength", "suffix_x_to_strength_3", {{EAffixRollEffectType::NUMBERIC, 16, 23, modStrength}}, (Level)16, EAffixType::SUFFIX, "of the Titan", {EAffixTag::ATTRIBUTE}});

            Modifier* modDexterity = database.modifiers.get("mod_dexterity");
            database.affixRolls.add(AffixRoll{4, "# to Dexterity", "suffix_x_to_dexterity_1", {{EAffixRollEffectType::NUMBERIC, 1, 10,  modDexterity}}, (Level)1, EAffixType::SUFFIX, "of Grace", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{5, "# to Dexterity", "suffix_x_to_dexterity_2", {{EAffixRollEffectType::NUMBERIC, 8, 18,  modDexterity}}, (Level)8, EAffixType::SUFFIX, "of Agility", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{6, "# to Dexterity", "suffix_x_to_dexterity_3", {{EAffixRollEffectType::NUMBERIC, 16, 23, modDexterity}}, (Level)16, EAffixType::SUFFIX, "of Precision", {EAffixTag::ATTRIBUTE}});

            Modifier* modIntelligence = database.modifiers.get("mod_intelligence");
            database.affixRolls.add(AffixRoll{7, "# to Intelligence", "suffix_x_to_intelligence_1", {{EAffixRollEffectType::NUMBERIC, 1, 10,  modIntelligence}}, (Level)1, EAffixType::SUFFIX, "of Insight", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{8, "# to Intelligence", "suffix_x_to_intelligence_2", {{EAffixRollEffectType::NUMBERIC, 8, 18,  modIntelligence}}, (Level)8, EAffixType::SUFFIX, "of Wisdom", {EAffixTag::ATTRIBUTE}});
            database.affixRolls.add(AffixRoll{9, "# to Intelligence", "suffix_x_to_intelligence_3", {{EAffixRollEffectType::NUMBERIC, 16, 23, modIntelligence}}, (Level)16, EAffixType::SUFFIX, "of Intellect", {EAffixTag::ATTRIBUTE}});
        }
    }

    ui->baseItemViewer->initialize(&database.itemBases);
    ui->modifierViewer->initialize(&database.modifiers);
    ui->affixRollsViewer->initialize(&database.affixRolls);


    CDataTableBase<AffixRoll> affixRolls;


    QObject::connect(ui->modifierViewer, &ModifierViewer::signalSelectedModifier, this,
                     [&](const Modifier* mod){

                     });

    QObject::connect(ui->affixRollsViewer, &AffixRollsViewer::signalSelectedRoll, this,
                     [&](const AffixRoll* roll){
                         ui->modifierViewer->selectModifier(roll->modRolls.front().modifier);
                     });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    CollapsedItemState newItem;

    //do RNG
    {
        Level receiverLevel = 1;
        Level dropLevel = 10;

        //Random base

        auto rngBase = QRandomGenerator::global()->bounded(0, (int)database.itemBases.getAll().size());
        newItem.base = &database.itemBases.getAll()[rngBase];

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
            /*
            int maxRolls = (newItem.rarity == ERarity::NORMAL) ? 0 :
                           ( (newItem.rarity == ERarity::MAGIC) ? PREFIX_MAX :
                           (( (newItem.rarity == ERarity::RARE) ? AFFIX_MAX : 0 )));
            */

            std::vector<RolledModifier> rolls;
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
                //Database.AffixDataTable.filter(base, tags, ilevel, AffixType)
                const AffixRoll* rolledAffix = nullptr;
                {
                    do{
                        auto rngAffixRoll = QRandomGenerator::global()->bounded(0, (int)database.affixRolls.getAll().size());
                        rolledAffix = &database.affixRolls.getAll()[rngAffixRoll];
                        qDebug() << "Rolli: " << rngAffixRoll << ", " << QString::fromStdString(toString(rolledAffix->affixType));
                    }while(!(rolledAffix->affixType == affixType && rolledAffix->level <= dropLevel));
                    if(affixType == EAffixType::PREFIX)
                        prefixCount++;
                    if(affixType == EAffixType::SUFFIX)
                        suffixCount++;
                    qDebug() << "Rolled Item: " << QString::fromStdString(toString(rolledAffix->affixType)) << ", " << QString::number(rolledAffix->id);
                }

                // Roll values
                /*
                {
                    RolledModifier rolledMod;
                    rolledMod.roll = rolledAffix;

                    for(auto modRoll: rolledAffix->modRolls)
                    {
                        auto rngValue = QRandomGenerator::global()->bounded((int)modRoll.minMax.min, (int)modRoll.minMax.max);
                        rolledMod.values.push_back(rngValue);
                    }

                    rolls.emplace_back(rolledMod);
                }
                */
                {

                    {

                        RolledModifier rolledMod;
                        rolledMod.roll = rolledAffix;

                        int i = 0;
                        for(auto modRoll: rolledAffix->modRolls)
                        {
                            MinMaxRoll minMax = modRoll.minMax;
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

    ui->collapsedItemViewer->setItem(newItem);
}


void MainWindow::on_pbFloatPhysical_clicked()
{
    CollapsedItemState newItem;

    newItem.base = &database.itemBases.getAll()[0];
    newItem.rarity = ERarity::RARE;
    RolledModifier rolledMod;
    {
        rolledMod.roll = database.affixRolls.get("prefix_flat_physical_damage_1");
        for(auto mr: rolledMod.roll->modRolls)
        {
            mr.modifier;
        }
    }
    newItem.prefix.push_back(rolledMod);


    ui->collapsedItemViewer->setItem(newItem);
}


void MainWindow::on_pbPctPhysical_clicked()
{

}

