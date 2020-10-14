#include "resultwindow.h"
#include "ui_resultwindow.h"

ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат тестування з 1 частини!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

     //Переходим к тесту для выбора специальности
    specialitytest = new SpecialityTest();
    connect(specialitytest, &SpecialityTest::resultwindow, this, &ResultWindow::show);
}

ResultWindow::~ResultWindow()
{
    delete ui;
}

void ResultWindow::on_direction_clicked()
{
    //Переходим к тесту для выбора специальности по напрвлениею человека

    specialitytest->show();  // Показываем  окно о авторе
    this->close();    // Закрываем основное окно





}
