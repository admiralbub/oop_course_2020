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

double rounD(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void ResultWindow::Count_Percent()
{
    Result.all_balls = Result.first + Result.second + Result.third+Result.fourth;
    double Temp = 100.0; // проценты
    Temp /= Result.all_balls;
    Result.first *= Temp;
    Result.second *= Temp;
    Result.third *= Temp;
    Result.fourth *= Temp;
    Result.first = rounD(Result.first);
    Result.second = rounD(Result.second);
    Result.third = rounD(Result.third);
    Result.fourth = rounD(Result.fourth);
    while(Result.first + Result.second + Result.third+Result.fourth > 100)
    {
        Result.fourth--;
    }
    while(Result.first + Result.second + Result.third+Result.fourth < 100)
    {
        Result.third++;
    }

}

void ResultWindow::SetIntValue()
{
    ui->balls_1->setText(QString::number(Result.first) + " %");
    ui->balls_2->setText(QString::number(Result.second) + " %");
    ui->balls_3->setText(QString::number(Result.third) + " %");
    ui->balls_4->setText(QString::number(Result.fourth)+ " %");
    SetColorPercent(ui->balls_1, Result.first);
    SetColorPercent(ui->balls_2, Result.second);
    SetColorPercent(ui->balls_3, Result.third);
    SetColorPercent(ui->balls_4, Result.fourth);
}

void ResultWindow::SetColorPercent(QLabel *l, double value)
{
    if(0.0 <= value <= 35.0)
    {
        l->setStyleSheet("color:red");
    }
    if(35.0 < value <= 45.0)
    {
        l->setStyleSheet("color:yellow");
    }
    if(45.0 < value < 100.0)
    {
        l->setStyleSheet("color:green");
    }
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
                        Result.first = xml_data.xml_stream_read.readElementText().toDouble();
                    }
                    else if(attr.value().toString() == "Man-Technics")
                    {
                        Result.second = xml_data.xml_stream_read.readElementText().toDouble();
                    }
                    else if(attr.value().toString() == "Man-Artistic-image")
                    {
                        Result.third = xml_data.xml_stream_read.readElementText().toDouble();
                    }
                    else
                    {
                        Result.fourth = xml_data.xml_stream_read.readElementText().toDouble();
                    }
                }

             }

         }
    }
    xml_data.file_xml.close();
    Count_Percent();
    SetIntValue();
}
