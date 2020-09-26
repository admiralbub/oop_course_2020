#include "testwindow.h"
#include "ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    //Тут грузим картинку для теста
    QPixmap pix(":/resources/image/1200px-Taras_Shevchenko_selfportrait_oil_1840-2.jpg");
    ui->label_pic->setPixmap(pix.scaled(300,400,Qt::KeepAspectRatio));

}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
