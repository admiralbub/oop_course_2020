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
    //Переходим к тесту для выбора специальности
    specialitytest = new SpecialtyWindow();
    connect(specialitytest, &SpecialtyWindow::resultspecialy, this, &ResultWindow::show);
}

ResultWindow::~ResultWindow() {
    delete ui;
}

void ResultWindow::on_direction_clicked() {
    //Переходим к тесту для выбора специальности
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
   Direction_name.push_back(Result[1].code);
   for (int i=2; i<=4; i++)
       if (Result[1].res == Result[i].res)
           Direction_name.push_back(Result[i].code);
}

void ResultWindow::Sort() {
    result temp;
    for (int i=0; i<4; i++)
        for (int j=1; j<4-i; j++)
            if (Result[j].res < Result[j+1].res) {
                temp = Result[j];
                Result[j] = Result[j+1];
                Result[j+1] = temp;
            }
}

void ResultWindow::SetIntValue() {
    ui->system_1->setText(Result[1].name);
    ui->system_2->setText(Result[2].name);
    ui->system_3->setText(Result[3].name);
    ui->system_4->setText(Result[4].name);
    ui->system_1->setStyleSheet("font-size:20px;");
    ui->system_2->setStyleSheet("font-size:20px;");
    ui->system_3->setStyleSheet("font-size:20px;");
    ui->system_4->setStyleSheet("font-size:20px;");
    ui->balls_1->setText(QString::number(Result[1].res) + " %");
    ui->balls_2->setText(QString::number(Result[2].res) + " %");
    ui->balls_3->setText(QString::number(Result[3].res) + " %");
    ui->balls_4->setText(QString::number(Result[4].res) + " %");
    SetColorPercent(ui->balls_1, Result[1].res);
    SetColorPercent(ui->balls_2, Result[2].res);
    SetColorPercent(ui->balls_3, Result[3].res);
    SetColorPercent(ui->balls_4, Result[4].res);
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
    Result[1] = {"Робота з людьми", "Man-Man", 0};
    Result[2] = {"Робота з технікою", "Man-Technics", 0};
    Result[3] = {"Творча робота", "Man-Artistic-image", 0};
    Result[4] = {"Робота зі знаковою системою", "Man-Sign-system", 0};

    xml_data.Init_xml_file_read("../oop_course_2020/DataBase/answer_directions.xml");
        while(xml_data.xml_stream_read.readNextStartElement()) {
           if(xml_data.xml_stream_read.name() == "result") {
            foreach(const QXmlStreamAttribute &attr, xml_data.xml_stream_read.attributes()) {
                if(attr.name() == "name") {
                    QString attribute_value = attr.value().toString();
                    if(attr.value().toString() == Result[1].code)
                        Result[1].res = xml_data.xml_stream_read.readElementText().toDouble()*12.5;
                    else if(attr.value().toString() == Result[2].code)
                        Result[2].res = xml_data.xml_stream_read.readElementText().toDouble()*12.5;
                    else if(attr.value().toString() == Result[3].code)
                        Result[3].res = xml_data.xml_stream_read.readElementText().toDouble()*12.5;
                    else
                        Result[4].res = xml_data.xml_stream_read.readElementText().toDouble()*12.5;
                }
             }
         }
    }
    xml_data.file_xml.close();
    Sort();
    SetIntValue();
    AddNameDirection_for_parse();
}
