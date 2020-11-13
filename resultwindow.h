#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <specialitytest.h>
#include "mydata.h"
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
    SpecialityTest *specialitytest;
    XML_Data xml_data;
    struct result
    {
        int all_balls;
        int first;
        int second;
        int third;
        int fourth;
    };
    result Result;
private:
    void InitStructResult();
public:
    void SetResults();
};

#endif // RESULTWINDOW_H
