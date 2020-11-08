#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
#include <resultwindow.h>
#include <mydata.h>

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
    void Process_Questions_count();
signals:
    void firstWindow();
private slots:

    void on_pushButton_menu_clicked();

    void on_answer_1_clicked();

    void on_answer_2_clicked();

    void on_answer_3_clicked();

private:
    Ui::TestWindow *ui;
    ResultWindow *resultWindow;
    MyData *data;
};

#endif // TESTWINDOW_H
