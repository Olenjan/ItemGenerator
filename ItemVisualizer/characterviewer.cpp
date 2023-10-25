#include "characterviewer.h"
#include "ui_characterviewer.h"

CharacterViewer::CharacterViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterViewer)
{
    ui->setupUi(this);
}

CharacterViewer::~CharacterViewer()
{
    delete ui;
}

void CharacterViewer::initialize(CharacterStats stats)
{
    m_Stats = stats;

    ui->listWidget->clear();

    QString nameStr = QString::fromStdString(stats.name);
    QString lvlStr = QString::number(stats.level);
    std::vector<std::pair<RollValue, QString>> modList =
    {
        {stats.life, "Life"},
        {stats.mana, "Mana"},
        {stats.stamina, "Stamina"},

        {stats.strength, "Strength"},
        {stats.dexterity, "Dexterity"},
        {stats.intelligence, "Intelligence"},

        {stats.minimumPhysicalDamage, "Minimum physical damage"},
        {stats.maximumPhysicalDamage, "Maximum physical damage"},
        {stats.increasedPhysicalDamage, "Increased physical damage"},

        {stats.armor, "Armor"}
    };

    for(auto mod: modList)
    {
        ui->listWidget->addItem(mod.second + " = " + QString::number(mod.first));
    }

}
