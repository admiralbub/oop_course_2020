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
    // Инициализируем третье окно
    resultWindow = new ResultWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(resultWindow, &ResultWindow::resultWindow, this, &TestWindow::show);
    data = new MyData(10); // указываем количество вопросов теста
    QString file_name = ":/resources/DataBase/questions_directions.csv";
    data->OpenForRead(data->file,file_name); // открываем нужный нам файл
    Restart_test();
}

TestWindow::~TestWindow()
{
    delete ui;
}

void TestWindow::Process_Questions_count()
{
    if(data->counter_question == data->getNumberAlQuestions()) // если текущий вопрос равен кол-ву вопросов(последний)
    {
        data->CloseFile();
        resultWindow->show(); // открываем окно с результатами
        this->close();
    }
    data->counter_question++; // порядковый номер вопроса увеличиваем на 1
}

void TestWindow::ReadFile()
{
    Process_Questions_count();
    ui->question->setText(data->stream.readLine());// считываем и записываем вопрос в строчку
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
    // TEST  XML-file
    // Не работает запись!
    QString file_name_xml = "answer_directions.xml";
    data->Init_xml_file(file_name_xml);
    if(data->file_xml.isOpen())
    {
        ui->answer_1->setText("Pisun");
    }
    data->Write_Answer_in_file();

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

void TestWindow::on_pushButton_first_clicked()
{
   Restart_test();
}

void TestWindow::Restart_test()
{
    ui->label_score->setText("Питання 1 з 10");
    data->counter_question = 0;
    data->stream.seek(0);
    // Здесь по идеи курсор в файле переносим на начало и должна происходить сортировка
    // Считываем новый вопрос
    ReadFile();
}

