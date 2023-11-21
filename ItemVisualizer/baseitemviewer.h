#ifndef BASEITEMVIEWER_H
#define BASEITEMVIEWER_H

#include <QWidget>
#include "data/entry/ItemBase.h"

namespace Ui {
class BaseItemViewer;
}

class BaseItemViewer : public QWidget
{
    Q_OBJECT

private:
    CDataTableBase<ItemBase>* m_ItemBaseDataTable;
public:
    explicit BaseItemViewer(QWidget *parent = nullptr);
    ~BaseItemViewer();

    void initialize(CDataTableBase<ItemBase>* itemBaseDataTable);
private:
    Ui::BaseItemViewer *ui;
};

#endif // BASEITEMVIEWER_H
