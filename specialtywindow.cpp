#include "specialtywindow.h"
#include "ui_specialtywindow.h"

SpecialtyWindow::SpecialtyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialtyWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат по обраному напрямку для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}

SpecialtyWindow::~SpecialtyWindow()
{
    delete ui;
}
