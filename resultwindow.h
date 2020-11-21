#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <specialtywindow.h>
#include "mydata.h"
#include <QLabel>
#include <cmath>
namespace Ui {
class ResultWindow;
}

class ResultWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultWindow(QWidget *parent = nullptr);
    ~ResultWindow();
signals:
    void resultWindow();
private slots:
    void on_direction_clicked();

    void on_first_clicked();

private:
    Ui::ResultWindow *ui;
    SpecialtyWindow *specialitytest;
    XML_Data xml_data;
    struct result
    {
        std::string name;
        QString code;
        double res;
    };
    QString Remark;
    result Result[5];
private:
    void InitStructResult();
    void Count_Percent();
    double MaxElementResult();
    void SetColorPercent(QLabel *l, double value);
    void SetIntValue();
    void Sort();
    //void RemarkSet();
    void AddNameDirection_for_parse();
public:
    QStringList Direction_name;
    void SetResults();
    void ReturnNameDirection_for_parse();
};

#endif // RESULTWINDOW_H
