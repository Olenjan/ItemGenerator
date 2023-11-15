#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    RandomNumberGenerator::initialize();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
