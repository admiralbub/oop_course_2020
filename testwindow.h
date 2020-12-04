#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include "mydata.h"
#include "resultwindow.h"
#include "result.h"

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
    void Read_questions();
    void Randomize_questions();
    void on_pushButton_first_clicked();

private:
    Ui::TestWindow *ui;
    ResultWindow *resultWindow;
    MyData *data;
    QStringList l;
    QStringList *mylist;
    Result rr[5];
    void Init_Struct_Dir_name();
    void Count_score(int score);
};

#endif // TESTWINDOW_H
