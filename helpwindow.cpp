#include "helpwindow.h"
#include "ui_helpwindow.h"
#include<QFile>


HelpWindow::HelpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);



    setWindowTitle("Допомога щодо використання програми!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    update();
}
HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_pushButton_further_clicked()
{

}

void HelpWindow::on_back_clicked()
{
    this->close();
    emit firstWindow();
}
