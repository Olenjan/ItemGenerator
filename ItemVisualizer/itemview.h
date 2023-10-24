#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include "data/CollapsedItemState.h"

namespace Ui {
class ItemView;
}

class ItemView : public QWidget
{
    Q_OBJECT

private:
    CollapsedItemState m_Item;
public:
    explicit ItemView(QWidget *parent = nullptr);
    ~ItemView();

    void setItem(const CollapsedItemState& item);

private:
    Ui::ItemView *ui;
};

#endif // ITEMVIEW_H
