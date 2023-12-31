#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include "data/RollDatabase.h"
#include "data/entry/Character.h"
#include "generator/ItemGenerator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


    CharacterStats myCharacter;
    std::shared_ptr<RollDatabase> database;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pbFloatPhysical_clicked();

    void on_pbPctPhysical_clicked();

    void on_pbZeroStats_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
