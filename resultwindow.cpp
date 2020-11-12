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
    SetResults();
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

bool ResultWindow::Check_Start_Elements()
{
     if(xml_data.xml_stream_read.readNext() == QXmlStreamReader::StartElement && xml_data.xml_stream_read.name() == "result")
         return true;
}

void ResultWindow::SetResults()
{
    xml_data.Init_xml_file_read("results.xml");
    if(Check_Start_Elements())
    {
        ui->balls_1->setText(xml_data.xml_stream_read.readElementText());
    }
    if(Check_Start_Elements())
    {
        ui->balls_2->setText(xml_data.xml_stream_read.readElementText());
    }
    if(Check_Start_Elements())
    {
        ui->balls_3->setText(xml_data.xml_stream_read.readElementText());
    }
    if(Check_Start_Elements())
    {
        ui->balls_4->setText(xml_data.xml_stream_read.readElementText());
    }

}
