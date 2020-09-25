#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);

}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
