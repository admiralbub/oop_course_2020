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

void ResultWindow::SetResults()
{
    xml_data.Init_xml_file_read("../oop_course_2020/DataBase/answer_directions.xml");
    if(xml_data.file_xml.isOpen())
    {
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
                        ui->balls_1->setText(xml_data.xml_stream_read.readElementText());
                    }
                    else if(attr.value().toString() == "Man-Technics")
                    {
                        ui->balls_2->setText(xml_data.xml_stream_read.readElementText());
                    }
                    else if(attr.value().toString() == "Man-Artistic-image")
                    {
                        ui->balls_3->setText(xml_data.xml_stream_read.readElementText());
                    }
                    else
                    {
                        ui->balls_4->setText(xml_data.xml_stream_read.readElementText());
                    }
                }

             }

           }
        }
    }
}
