#include "itemview.h"
#include "ui_itemview.h"

ItemView::ItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemView)
{
    ui->setupUi(this);
}

void ItemView::setItem(const CollapsedItemState& item)
{
    m_Item = item;

    ui->lblBaseValue->setText(QString::fromStdString(m_Item.base->name));
    ui->lblNameValue->setText(QString::fromStdString(m_Item.name));
    ui->lblRarityValue->setText(QString::fromStdString(toString(m_Item.rarity)));

    ui->lblImplicitValue->setText(QString::number(m_Item.implicit.size()));
    ui->lblPrefixValue->setText(QString::number(m_Item.prefix.size()));
    ui->lblSuffixValue->setText(QString::number(m_Item.suffix.size()));



    QString itemText;
    {
        itemText.append(QString::fromStdString(toString(m_Item.rarity))).append("\n");
        itemText.append(QString::fromStdString(m_Item.name)).append("\n");

        for(auto i: m_Item.implicit)
        {
            itemText.append("Implicit:");
            QString rolledName = QString::fromStdString(i.getRolledName());
            itemText.append(rolledName);
            itemText.append("\n");
        }


        for(auto i: m_Item.prefix)
        {
            itemText.append("Prefix:");
            QString rolledName = QString::fromStdString(i.getRolledName());
            itemText.append(rolledName);

            itemText.append("\n");
        }


        for(auto i: m_Item.suffix)
        {
            itemText.append("Suffix:");
            QString rolledName = QString::fromStdString(i.getRolledName());
            itemText.append(rolledName);
            itemText.append("\n");
        }
    }
    ui->itemText->setText(itemText);

}

ItemView::~ItemView()
{
    delete ui;
}
