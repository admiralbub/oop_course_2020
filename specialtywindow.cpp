#include "specialtywindow.h"
#include "mainwindow.h"
#include "ui_specialtywindow.h"
#include<QDesktopServices>
#include<QUrl>
SpecialtyWindow::SpecialtyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialtyWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат по обраному напрямку для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    resultwindoW = new ResultWindow();
    connect(this, &SpecialtyWindow::WriteSpecialityinTextBrowser, resultwindoW, &ResultWindow::ReturnNameDirection_for_parse);
    WriteSpecialityinTextBrowser();
}

SpecialtyWindow::~SpecialtyWindow()
{
    delete ui;
}

void SpecialtyWindow::on_site_nuzp_clicked()
{
    QString link = "https://pk.zp.edu.ua/fakultety-ta-napryamy-pidhotovky";
    QDesktopServices::openUrl(QUrl(link));
}

void SpecialtyWindow::on_menu_button_clicked()
{
    this->close();
    auto win = new MainWindow();
    win->setAttribute( Qt::WA_DeleteOnClose );
    win->show();
}

void SpecialtyWindow::WriteSpecialityinTextBrowser()
{
    QStringList l = resultwindoW->ReturnNameDirection_for_parse();
    myData->Init_xml_file_read("../oop_course_2020/DataBase/speciality.xml");
    QString all_speciality;
    while(myData->xml_stream_read.readNextStartElement())
    {
       if(myData->xml_stream_read.name() == "direction")
       {
           foreach(const QXmlStreamAttribute &attr, myData->xml_stream_read.attributes())
           {
               if(attr.name() == "name")
               {
                   QString attribute_value = attr.value().toString();
                   if((attr.value().toString() == "Man-Man" && l.contains("Man-Man")) ||
                      (attr.value().toString() == "Man-Technics" && l.contains("Man_Technics")) ||
                      (attr.value().toString() == "Man-Artistic-image" && l.contains("Man-Artistic-image"))||
                      (attr.value().toString() == "Man-Sign-system" && l.contains("Man-Sign-system")))
                   {
                      myData->xml_stream_read.readNextStartElement();
                      while(myData->xml_stream_read.name() == "speciality")
                      {
                          all_speciality += myData->xml_stream_read.readElementText() + "\n";
                          myData->xml_stream_read.readNextStartElement();
                      }
                   }
               }
             }
       }

    }
    ui->textBrowser->setText(all_speciality);
    myData->file_xml.close();
    myData->~XML_Data();
}
