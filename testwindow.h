#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <resultwindow.h>
#include <mydata.h>
#include <resultwindow.h>
namespace Ui {
class TestWindow;
}

class TestWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestWindow(QWidget *parent = nullptr);
    ~TestWindow();
private:
    void ReadFile();
    bool Process_Questions_count();
signals:
    void firstWindow();
private slots:

    void on_pushButton_menu_clicked();

    void on_answer_1_clicked();

    void on_answer_2_clicked();

    void on_answer_3_clicked();

    void Restart_test();

    void Mixer_for_questions();

    void on_pushButton_first_clicked();

private:
    Ui::TestWindow *ui;
    ResultWindow *resultWindow;
    MyData *data;
    QStringList l;
    QStringList *mylist;
    struct Directions_name
    {
        int Man_Man;
        int Man_Technics;
        int Man_Artistic_Image;
        int Man_Sign_System;
    };
    Directions_name MainStruct;
    void Init_Struct_Dir_name();
    void Count_direct_score_if_answer_true();
    void Count_direct_score_if_answer_not_determined();
};

#endif // TESTWINDOW_H
