#include "resultwindow.h"
#include "ui_resultwindow.h"
#include "mainwindow.h"
#include <QDir>
#include <cmath>
ResultWindow::ResultWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ResultWindow) {
    ui->setupUi(this);
    setWindowTitle("Результат тестування");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    setMinimumSize(877, 672);
    setMaximumSize(877, 672);
     setWindowIcon(QIcon(":/resources/image/header-object.png"));
    specialitytest = new SpecialtyWindow();
    connect(specialitytest, &SpecialtyWindow::resultspecialy, this, &ResultWindow::show);
}

ResultWindow::~ResultWindow() {
    delete ui;
}

void ResultWindow::on_direction_clicked() {
    specialitytest->show();
    this->close();
    ReturnNameDirection_for_parse();
}

void ResultWindow::on_first_clicked() {
    this->close();
    auto win = new  MainWindow();
    win->show();
}

void ResultWindow::ReturnNameDirection_for_parse() {
  specialitytest->WriteSpecialityinTextBrowser(Direction_name);
}

void ResultWindow::AddNameDirection_for_parse() {
   Direction_name.push_back(r[1].getCode());
   for (int i=2; i<=4; i++)
       if (r[1].getRes() == r[i].getRes())
           Direction_name.push_back(r[i].getCode());
}

void ResultWindow::Sort() {
    Result temp;
    for (int i=0; i<4; i++)
        for (int j=1; j<4-i; j++)
            if (r[j].getRes() < r[j+1].getRes()) {
                temp = r[j];
                r[j] = r[j+1];
                r[j+1] = temp;
            }
}

void ResultWindow::SetIntValue() {
    ui->system_1->setText(r[1].getName());
    ui->system_2->setText(r[2].getName());
    ui->system_3->setText(r[3].getName());
    ui->system_4->setText(r[4].getName());
    ui->system_1->setStyleSheet("font-size:20px;");
    ui->system_2->setStyleSheet("font-size:20px;");
    ui->system_3->setStyleSheet("font-size:20px;");
    ui->system_4->setStyleSheet("font-size:20px;");
    ui->balls_1->setText(QString::number(r[1].getRes()) + " %");
    ui->balls_2->setText(QString::number(r[2].getRes()) + " %");
    ui->balls_3->setText(QString::number(r[3].getRes()) + " %");
    ui->balls_4->setText(QString::number(r[4].getRes()) + " %");
    SetColorPercent(ui->balls_1, r[1].getRes());
    SetColorPercent(ui->balls_2, r[2].getRes());
    SetColorPercent(ui->balls_3, r[3].getRes());
    SetColorPercent(ui->balls_4, r[4].getRes());
}

void ResultWindow::SetColorPercent(QLabel *l, double value) {
    int Test = (int)value;
    if(Test >= 35)
        l->setStyleSheet("font-size:20px;font-weight:700;color:#55ff00;");
    else if(Test >= 25)
        l->setStyleSheet("font-size:20px;font-weight:700;color:#ffff00;");
    else
        l->setStyleSheet("font-size:20px;font-weight:700;color:#FFA500;");
}

void ResultWindow::SetResults() {
    r[1].set("Робота з людьми", "Man-Man", 0);
    r[2].set("Робота з технікою", "Man-Technics", 0);
    r[3].set("Творча робота", "Man-Artistic-image", 0);
    r[4].set("Робота зі знаковою системою", "Man-Sign-system", 0);

    xml_data.Init_xml_file_read("../oop_course_2020/DataBase/answer_directions.xml");
        while(xml_data.xml_stream_read.readNextStartElement()) {
           if(xml_data.xml_stream_read.name() == "result") {
            foreach(const QXmlStreamAttribute &attr, xml_data.xml_stream_read.attributes()) {
                if(attr.name() == "name") {
                    QString attribute_value = attr.value().toString();
                    if(attr.value().toString() == r[1].getCode())
                        r[1].setRes(xml_data.xml_stream_read.readElementText().toDouble()*12.5);
                    else if(attr.value().toString() == r[2].getCode())
                        r[2].setRes(xml_data.xml_stream_read.readElementText().toDouble()*12.5);
                    else if(attr.value().toString() == r[3].getCode())
                        r[3].setRes(xml_data.xml_stream_read.readElementText().toDouble()*12.5);
                    else
                        r[4].setRes(xml_data.xml_stream_read.readElementText().toDouble()*12.5);
                }
             }
         }
    }
    xml_data.file_xml.close();
    Sort();
    SetIntValue();
    AddNameDirection_for_parse();
}
