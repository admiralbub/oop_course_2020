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

void ResultWindow::SetResults()
{
    xml_data.Init_xml_file_read("../oop_course_2020/DataBase/answer_directions.xml");
        if(xml_data.file_xml.isOpen())
        {
         while(!xml_data.file_xml.atEnd())
         {
           ui->balls_1->setText(xml_data.Parse_xml_element());
         }
    }
}
