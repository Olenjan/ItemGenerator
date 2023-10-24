#include "baseitemviewer.h"
#include "ui_baseitemviewer.h"

BaseItemViewer::BaseItemViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseItemViewer)
{
    ui->setupUi(this);
}


BaseItemViewer::~BaseItemViewer()
{
    delete ui;
}


void BaseItemViewer::initialize(CDataTableBase<ItemBase>* itemBaseDataTable)
{
    m_ItemBaseDataTable = itemBaseDataTable;

    ui->listWidget->clear();
    for(const auto& i: m_ItemBaseDataTable->getAll())
    {
        ui->listWidget->addItem(QString::fromStdString(i.name));
    }
}
