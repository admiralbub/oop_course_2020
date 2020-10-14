#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат тестування з 1 частини!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}
