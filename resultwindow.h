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
        double all_balls;
        double first;
        double second;
        double third;
        double fourth;
    };
    result Result;
private:
    void InitStructResult();
    void Count_Percent();
    double MaxElementResult(double max);
    void SetColorPercent(QLabel *l, double value);
    void SetIntValue();
public:
    void SetResults();
};

#endif // RESULTWINDOW_H
