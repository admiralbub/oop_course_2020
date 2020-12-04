#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <cmath>
#include "specialtywindow.h"
#include "mydata.h"
#include "result.h"

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
    QString Remark;
    Result r[5];
private:
    void InitStructResult();
    void Count_Percent();
    double MaxElementResult();
    void SetColorPercent(QLabel *l, double value);
    void SetIntValue();
    void Sort();
    void AddNameDirection_for_parse();
public:
    QStringList Direction_name;
    void SetResults();
    void ReturnNameDirection_for_parse();
};

#endif // RESULTWINDOW_H
