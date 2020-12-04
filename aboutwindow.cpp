#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include <QPixmap>
AboutWindow::AboutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    setWindowTitle("Інформація про розробників");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setWindowIcon(QIcon(":/resources/image/header-object.png"));
    QPixmap pix(":/resources/image/vstup-na-budzhet-2019_1.jpg");
    ui->label_image->setPixmap(pix.scaled(300,600,Qt::KeepAspectRatio));
    setMinimumSize(877, 641);
            setMaximumSize(877, 641);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}


void AboutWindow::on_back_clicked()
{
    this->close();
    emit firstWindow();
}
