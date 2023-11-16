#include "affixrollsviewer.h"
#include "ui_affixrollsviewer.h"

AffixRollsViewer::AffixRollsViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AffixRollsViewer)
{
    ui->setupUi(this);
}

AffixRollsViewer::~AffixRollsViewer()
{
    delete ui;
}

void AffixRollsViewer::initialize(CDataTableBase<PossibleAffix>* affixRollsDataTable)
{
    m_AffixRollsDataTable = affixRollsDataTable;

    ui->listWidget->clear();
    for(const PossibleAffix& i: m_AffixRollsDataTable->getAll())
    {
        auto strAffixType = toString(i.affixType);

        QString tagList;
        for(auto tag: i.tags)
        {
            if(tagList.size() > 0)
                tagList.append(", ");

            tagList.append(QString::fromStdString(toString(tag)));
        }

        QString displayName = "[" + QString::fromStdString(strAffixType)+ "] [T" +QString::number((int)i.tier)+ "] " + QString::fromStdString(i.getRangeRollName()) + " | " + tagList + "; " + QString::number(i.level);

        ui->listWidget->addItem(displayName);
    }
}

void AffixRollsViewer::on_listWidget_currentRowChanged(int currentRow)
{

    const PossibleAffix* ptr = &m_AffixRollsDataTable->getAll()[currentRow];
    if(ptr)
    {
        qDebug() << "Selected Roll: " << ptr << " = " << ptr->id << "; " << QString::fromStdString(ptr->name);
        emit signalSelectedRoll(ptr);
    }
}

