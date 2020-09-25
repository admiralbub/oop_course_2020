 #include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ Запорізька політехніка!");
    w.setWindowFlags(Qt::Dialog);
    w.show();
    return a.exec();
}
