#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QDir>
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
    // commit
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

void ResultWindow::on_first_clicked()
{
    this->close();
}

void ResultWindow::InitStructResult()
{

}

void ResultWindow::Count_Percent()
{
    Result.all_balls = Result.first + Result.second + Result.third+Result.fourth;
    int Temp = 100; // проценты
    Temp /= Result.all_balls;
    Result.first *= Temp;
    Result.second *= Temp;
    Result.third *= Temp;
    Result.fourth *= Temp;
}

void ResultWindow::SetIntValue()
{
    ui->balls_1->setText(QString::number(Result.first) + " %");
    ui->balls_2->setText(QString::number(Result.second) + " %");
    ui->balls_3->setText(QString::number(Result.third) + " %");
    ui->balls_4->setText(QString::number(Result.fourth)+ " %");
}

void ResultWindow::SetResults()
{
    xml_data.Init_xml_file_read("../oop_course_2020/DataBase/answer_directions.xml");
        while(xml_data.xml_stream_read.readNextStartElement())
        {
           if(xml_data.xml_stream_read.name() == "result")
           {
            foreach(const QXmlStreamAttribute &attr, xml_data.xml_stream_read.attributes())
            {
                if(attr.name() == "name")
                {
                    QString attribute_value = attr.value().toString();
                    if(attr.value().toString() == "Man-Man")
                    {
                        Result.first = xml_data.xml_stream_read.readElementText().toInt() + 1;
                    }
                    else if(attr.value().toString() == "Man-Technics")
                    {
                        Result.second = xml_data.xml_stream_read.readElementText().toInt() + 1;
                    }
                    else if(attr.value().toString() == "Man-Artistic-image")
                    {
                        Result.third = xml_data.xml_stream_read.readElementText().toInt() + 1;
                    }
                    else
                    {
                        Result.fourth = xml_data.xml_stream_read.readElementText().toInt() + 1;
                    }
                }

             }

         }
    }
    xml_data.file_xml.close();
    Count_Percent();
    SetIntValue();
}
