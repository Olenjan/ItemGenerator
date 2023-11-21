#ifndef MODIFIERVIEWER_H
#define MODIFIERVIEWER_H

#include <QDebug>
#include <QWidget>
#include "data/entry/Modifier.h"

namespace Ui {
class ModifierViewer;
}

class ModifierViewer : public QWidget
{
    Q_OBJECT
private:
    CDataTableBase<Modifier>* m_ModifierDataTable;
public:
    explicit ModifierViewer(QWidget *parent = nullptr);
    ~ModifierViewer();

    void initialize(CDataTableBase<Modifier>* modifierDataTable);

    void selectModifier(const Modifier* mod);
signals:
    void signalSelectedModifier(const Modifier* mod);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::ModifierViewer *ui;
};

#endif // MODIFIERVIEWER_H
