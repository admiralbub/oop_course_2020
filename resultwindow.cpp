#include "resultwindow.h"
#include "ui_resultwindow.h"
#include <QDir>
#include <cmath>
ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат тестування з 1 частини!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

     //Переходим к тесту для выбора специальности
    specialitytest = new SpecialtyWindow();
    connect(specialitytest, &SpecialtyWindow::resultspecialy, this, &ResultWindow::show);
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
    ReturnNameDirection_for_parse();
}

void ResultWindow::on_first_clicked()
{
    this->close();
}

double ResultWindow::MaxElementResult()
{
    double max = Result.first;
    if(Result.second > max)
    {
        max = Result.second;
    }
    if(Result.third > max)
    {
        max = Result.third;
    }
    if(Result.fourth > max)
    {
        max = Result.fourth;
    }
    return max;
}

void ResultWindow::ReturnNameDirection_for_parse()
{
  specialitytest->WriteSpecialityinTextBrowser(Direction_name);
}

void ResultWindow::AddNameDirection_for_parse(QString name)
{
   Direction_name.push_back(name);
}

void ResultWindow::RemarkSet()
{
    double newmax = MaxElementResult();
    int count = 0;
    QString line;
    Remark = "Напрямок, що найкраще підходить :\n";
    if(newmax == Result.first)
    {
            line += "Людина - людина\n";
            count++;
            AddNameDirection_for_parse("Man-Man");
        }
        if(newmax == Result.second)
        {
            line += "Людина - техніка\n";
            count++;
            AddNameDirection_for_parse("Man-Technics");
        }
        if(newmax == Result.third)
        {
            line += "Людина - художній образ\n";
            count++;
            AddNameDirection_for_parse("Man-Artistic-image");
        }

        if(newmax == Result.fourth)
        {
            line += "Людина - знакова система\n";
            count++;
            AddNameDirection_for_parse("Man-Sign-system");
        }
    if(count >= 2)
    {
        Remark = "Напрямки, що найкраще підходять :\n";
    }
    Remark += line;
    ui->system_info->setText(Remark);
    ui->system_info->setStyleSheet("font-size:18px");
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
    int Test = (int)value;
    if(Test >= 35)
    {
        l->setStyleSheet("font-size:20px;font-weight:700;color:#55ff00;");
    }
    else if(Test >= 25)
    {
        l->setStyleSheet("font-size:20px;font-weight:700;color:#ffff00;");
    }
    else
    {
        l->setStyleSheet("font-size:20px;font-weight:700;color:#FFA500;");
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
    RemarkSet();
}
