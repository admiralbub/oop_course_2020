#include "testwindow.h"
#include "ui_testwindow.h"
#include <QTextCodec>
#include <QDir>
#include <QDebug>

TestWindow::TestWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestWindow)
{
    ui->setupUi(this);
    setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setMinimumSize(877, 641);
    setMaximumSize(877, 641);
    //Тут грузим картинку для теста
    // Инициализируем третье окно
    resultWindow = new ResultWindow();
    // подключаем к слоту запуска главного окна по кнопке в третьем окне
    connect(resultWindow, &ResultWindow::resultWindow, this, &TestWindow::show);
    connect(this,&TestWindow::close, resultWindow, &ResultWindow::SetResults);
    data = new MyData(16); // указываем количество вопросов теста
    QString file_name = ":/resources/DataBase/questions_directions.csv";
    data->OpenForRead(data->file,file_name); // открываем нужный нам файл
    mylist = new QStringList();
    Init_Struct_Dir_name();
    Read_questions();
    Randomize_questions();
    Restart_test();
}

void TestWindow::Init_Struct_Dir_name()
{
    MainStruct.Man_Man = 0;
    MainStruct.Man_Technics = 0;
    MainStruct.Man_Sign_System = 0;
    MainStruct.Man_Artistic_Image = 0;
}

TestWindow::~TestWindow()
{
    delete ui;
    delete data;
}

bool TestWindow::Process_Questions_count()
{
    if(data->counter_question == data->getNumberAlQuestions()) // если текущий вопрос равен кол-ву вопросов(последний)
    {
        data->Write_Root_Element();
        data->Write_Answer_in_file("Man-Man",QString::number(MainStruct.Man_Man));
        data->Write_Answer_in_file("Man-Technics",QString::number(MainStruct.Man_Technics));
        data->Write_Answer_in_file("Man-Artistic-image",QString::number(MainStruct.Man_Artistic_Image));
        data->Write_Answer_in_file("Man-Sign-system",QString::number(MainStruct.Man_Sign_System));
        data->Write_End_Root_Element();
        data->CloseFile();
        // Закрывать xml файл не надо, он закрывается одновременно с файлом с вопросами! функция data->CloseFile
        resultWindow->show(); // открываем окно с результатами
        resultWindow->SetResults();
        this->close();
        return false;
    }
    data->counter_question++; // порядковый номер вопроса увеличиваем на 1
    return true;
}

void TestWindow::Count_direct_score_if_answer_true()
{
   if(l[1] == "Man-Man")
   {
       MainStruct.Man_Man+=2;
   }
   else if(l[1] == "Man-Technics")
   {
       MainStruct.Man_Technics+=2;
   }
   else if(l[1] == "Man-Artistic-image")
   {
       MainStruct.Man_Artistic_Image+=2;
   }
   else
   {
       MainStruct.Man_Sign_System+=2;
   }

}

void TestWindow::Count_direct_score_if_answer_not_determined()
{
    if(l[1] == "Man-Man")
    {
        MainStruct.Man_Man+=1;
    }
    else if(l[1] == "Man-Technics")
    {
        MainStruct.Man_Technics+=1;
    }
    else if(l[1] == "Man-Artistic-image")
    {
        MainStruct.Man_Artistic_Image+=1;
    }
    else
    {
        MainStruct.Man_Sign_System+=1;
    }
}

void TestWindow::Read_questions()
{
    if(data->file.isOpen())
        while(!data->stream.atEnd())
            mylist->push_back(data->stream.readLine());
}

void TestWindow::Randomize_questions()
{
    srand(time(0));
    for (int i = mylist->count() - 1; i >= 1; i--)
       {
          int j = rand()%(i + 1);
          mylist->swap(i,j);
       }

}

void TestWindow::ReadFile()
{
    if(Process_Questions_count())
    {
        QString line = mylist->at(data->counter_question - 1);
        l = line.split(';'); // первый элемент - вопрос, второй - направление
        ui->question->setText(l[0]);// считываем и записываем вопрос в строчку
        if(data->counter_question >= 2) // если номер вопроса больше или равен
        {
            QString convert_int;
            ui->label_score->setText("Питання " + convert_int.setNum(data->counter_question) + " з 16");
        }
    }
}

void TestWindow::on_pushButton_menu_clicked()
{
    this->close();
    emit firstWindow();
}

void TestWindow::on_answer_1_clicked()
{
    Count_direct_score_if_answer_true();
    ReadFile();
}

void TestWindow::on_answer_2_clicked()
{
    ReadFile();
}

void TestWindow::on_answer_3_clicked()
{
    Count_direct_score_if_answer_not_determined();
    ReadFile();
}

void TestWindow::on_pushButton_first_clicked()
{
   Restart_test();
}

void TestWindow::Restart_test()
{
    if(data->file_xml.isOpen())
    {
    Init_Struct_Dir_name();
    data->file_xml.remove();
    }
    QString file_name_xml = "../oop_course_2020/DataBase/answer_directions.xml";
    data->Init_xml_file_write(file_name_xml);
    ui->label_score->setText("Питання 1 з 16");
    data->counter_question = 0;
    data->stream.seek(0);
    // Здесь курсор в файле переносим на начало и должна происходить сортировка
    // Считываем новый вопрос
    ReadFile();
}
