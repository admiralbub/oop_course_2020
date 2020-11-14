#include "specialtywindow.h"
#include "mainwindow.h"
#include "ui_specialtywindow.h"
#include<QDesktopServices>
#include<QUrl>
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

void SpecialtyWindow::on_exit_clicked()
{
    QString link = "https://pk.zp.edu.ua/fakultety-ta-napryamy-pidhotovky";
    QDesktopServices::openUrl(QUrl(link));
}

void SpecialtyWindow::on_menu_button_clicked()
{

}
