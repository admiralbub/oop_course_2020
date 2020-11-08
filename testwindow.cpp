#include "testwindow.h"
#include "ui_testwindow.h"
#include <QTextCodec>

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
    data = new MyData(10); // указываем количество вопросов теста
    QString file_name = ":/resources/DataBase/questions_directions.csv";
    data->initFileAndOpenForRead(file_name); // открываем нужный нам файл
    ReadFile();
}

TestWindow::~TestWindow()
{
    delete data;
    delete ui;
}

void TestWindow::Process_Questions_count()
{
    if(data->counter_question == data->getNumberAlQuestions()) // если текущий вопрос равен кол-ву вопросов(последний)
    {
        resultWindow->show(); // открываем окно с результатами
        this->close();
    }
    data->counter_question++; // порядковый номер вопроса увеличиваем на 1
}

void TestWindow::ReadFile()
{
    Process_Questions_count();
    ui->variant1->setText(data->stream.readLine());// считываем и записываем вопросы в строчки
    ui->variant2->setText(data->stream.readLine());
    ui->variant3->setText(data->stream.readLine());
    ui->variant4->setText(data->stream.readLine());
    if(data->counter_question >= 2) // если номер вопроса больше или равен
    {
        QString convert_int;
        ui->label_score->setText("Питання " + convert_int.setNum(data->counter_question) + " з 10");
        // формируем строку "номер вопроса"
    }
}

void TestWindow::on_pushButton_menu_clicked()
{
    this->close();
    emit firstWindow();
}

void TestWindow::on_answer_1_clicked()
{
    ReadFile();
}

void TestWindow::on_answer_2_clicked()
{
    ReadFile();
}

void TestWindow::on_answer_3_clicked()
{
    ReadFile();
}

void TestWindow::on_answer_4_clicked()
{
    ReadFile();
}
