#include "helpwindow.h"
#include "ui_helpwindow.h"
#include<QFile>


int num,ind,sum;

vector<vector<string>> db;

HelpWindow::HelpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);

    QFile file("C:/Users/artem/Desktop/OOP course project/test/untitled12/database.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

        num=0;
        ind=0;

    while (!file.atEnd()) {
       //QByteArray line = file.readLine();
       stringstream ss(file.readLine().toStdString());
       vector<string> res;
       while(ss.good()) {
           string substr;
           getline(ss, substr, ':');
           res.push_back(substr);
       }
       db.push_back(res);
       num++;
    }

    setWindowTitle("Допомога щодо використання програми!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    update();
}
HelpWindow::~HelpWindow()
{
    delete ui;
}
void HelpWindow::update() {
    string s=db[ind][0];
    ui->label_heading->setText(QString::fromStdString(db[ind][0]));
    ui->label_text->setText(QString::fromStdString(db[ind][1]));
}
void HelpWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

void HelpWindow::on_pushButton_further_clicked()
{
    sum++;
    if (++ind<num) {
         update();
    } else {
        ui->pushButton_further->setEnabled(false);
    }
}
