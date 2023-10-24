#include "modifierviewer.h"
#include "ui_modifierviewer.h"

ModifierViewer::ModifierViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModifierViewer)
{
    ui->setupUi(this);
}

ModifierViewer::~ModifierViewer()
{
    delete ui;
}

void ModifierViewer::initialize(CDataTableBase<Modifier>* modifierDataTable)
{
    m_ModifierDataTable = modifierDataTable;

    ui->listWidget->clear();
    for(const auto& i: m_ModifierDataTable->getAll())
    {
        ui->listWidget->addItem(QString::fromStdString(i.name));
    }
}

void ModifierViewer::selectModifier(const Modifier* mod)
{
    int row = 0;
    for(const Modifier& m: m_ModifierDataTable->getAll())
    {
        if(&m == mod)
        {
            break;
        }
        row++;
    }

    ui->listWidget->setCurrentRow(row);
}

void ModifierViewer::on_listWidget_currentRowChanged(int currentRow)
{
    const Modifier* ptr = &m_ModifierDataTable->getAll()[currentRow];
    if(ptr)
    {
        qDebug() << "Selected modifier: " << ptr << " = " << ptr->id << "; " << QString::fromStdString(ptr->name);
        emit signalSelectedModifier(ptr);
    }
}

