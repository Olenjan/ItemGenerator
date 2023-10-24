#ifndef AFFIXROLLSVIEWER_H
#define AFFIXROLLSVIEWER_H

#include <QDebug>
#include <QWidget>
#include "data/AffixRoll.h"
#include "data/AffixType.h"

namespace Ui {
class AffixRollsViewer;
}

class AffixRollsViewer : public QWidget
{
    Q_OBJECT
private:
    CDataTableBase<AffixRoll>* m_AffixRollsDataTable;
public:
    explicit AffixRollsViewer(QWidget *parent = nullptr);
    ~AffixRollsViewer();

    void initialize(CDataTableBase<AffixRoll>* affixRollsDataTable);

signals:
    void signalSelectedRoll(const AffixRoll* roll);

private slots:
    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::AffixRollsViewer *ui;
};

#endif // AFFIXROLLSVIEWER_H
