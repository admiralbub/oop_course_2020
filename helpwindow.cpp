#include "helpwindow.h"
#include "ui_helpwindow.h"
#include<QFile>
#include<QDesktopServices>
#include<QUrl>
HelpWindow::HelpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpWindow) {
    ui->setupUi(this);

    setWindowTitle("Допомога щодо використання програми");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    update();
    //Подгружаем основное лого ЗНТУ
    QPixmap pix(":/resources/image/header-object.png");
    ui->label_pic->setPixmap(pix.scaled(100,600,Qt::KeepAspectRatio));

}
HelpWindow::~HelpWindow()
{
    delete ui;
}


void HelpWindow::on_back_clicked()
{
    this->close();
    emit firstWindow();

}


void HelpWindow::on_telegram_clicked()
{
    QString link = "http://t.me/artemdikarev";
    QDesktopServices::openUrl(QUrl(link));

}

void HelpWindow::on_viber_clicked()
{
    QString link = "http://memesmix.net/media/created/6kua5l.jpg";
    QDesktopServices::openUrl(QUrl(link));
}
