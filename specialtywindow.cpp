#include "specialtywindow.h"
#include "ui_specialtywindow.h"

SpecialtyWindow::SpecialtyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialtyWindow)
{
    ui->setupUi(this);
}

SpecialtyWindow::~SpecialtyWindow()
{
    delete ui;
}
