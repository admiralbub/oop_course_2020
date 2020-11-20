#include "specialtywindow.h"
#include "mainwindow.h"
#include "ui_specialtywindow.h"
#include <QDesktopServices>
#include <QUrl>
#include <QThread>
#include <QMediaPlayer>
SpecialtyWindow::SpecialtyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialtyWindow)
{
    ui->setupUi(this);
    setWindowTitle("Результат по обраному напрямку для навчання в НУ «Запорізька політехніка»");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    resultdata = new XML_Data();

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

void SpecialtyWindow::ReadSpeciality()
{
    resultdata->xml_stream_read.readNextStartElement();
    while(resultdata->xml_stream_read.name() == "speciality")
    {
        all_speciality += resultdata->xml_stream_read.readElementText() + "\n";
        resultdata->xml_stream_read.readNextStartElement();
    }
}


void SpecialtyWindow::WriteSpecialityinTextBrowser(QStringList &l)
{
   resultdata->Init_xml_file_read(":/resources/DataBase/speciality.xml");
       while(resultdata->xml_stream_read.readNextStartElement())
       {
             while(resultdata->xml_stream_read.name() != "direction")
             {
                 resultdata->xml_stream_read.readNextStartElement();
             }
             foreach(const QXmlStreamAttribute &attr, resultdata->xml_stream_read.attributes())
             {
                 if(attr.name() == "name")
                 {
                     QString attribute_value = attr.value().toString();
                     if(l.contains(attr.value().toString()))
                     {
                           ReadSpeciality();
                     }
                 }
             }
       }

  ui->textBrowser->setText(all_speciality);
  ui->textBrowser->setStyleSheet("font-size:16px");
  resultdata->file_xml.close();
  resultdata->~XML_Data();
}
