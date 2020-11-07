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

    // Инициализируем третье окно
    resultWindow = new ResultWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(resultWindow, &ResultWindow::resultWindow, this, &TestWindow::show);
    ReadFile();
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::ReadFile()
{
    QString file_name = ":/resources/file/database.txt";
    data.initFileAndOpenForRead(file_name);
    // temporary check open file
    if(data.file.isOpen())
    {
        ui->label_6->setText("File is open");
    }
    else
    {
        ui->label_6->setText("File not open!");
    }
}

void TestWindow::on_pushButton_menu_clicked()
{
    this->close();
    emit firstWindow();
}

void TestWindow::on_answer_1_clicked()
{
    //Тут пишем код при нажатие на 1 ответ
    resultWindow->show();
    this->close();
}

void TestWindow::on_answer_2_clicked()
{
    //Тут пишем код при нажатие на 2 ответ
}

void TestWindow::on_answer_3_clicked()
{
    //Тут пишем код при нажатие на 3 ответ
}

void TestWindow::on_answer_4_clicked()
{
    //Тут пишем код при нажатие на 4 ответ
}
