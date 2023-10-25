#ifndef CHARACTERVIEWER_H
#define CHARACTERVIEWER_H

#include <QDebug>
#include <QWidget>

#include "data/Character.h"

namespace Ui {
class CharacterViewer;
}

class CharacterViewer : public QWidget
{
    Q_OBJECT
private:
    CharacterStats m_Stats;
public:
    explicit CharacterViewer(QWidget *parent = nullptr);
    ~CharacterViewer();

    void initialize(CharacterStats stats);

private:
    Ui::CharacterViewer *ui;
};

#endif // CHARACTERVIEWER_H
