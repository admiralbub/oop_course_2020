#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QMainWindow>
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
signals:
    void firstWindow();
private slots:

    void on_pushButton_menu_clicked();

    void on_answer_1_clicked();

    void on_answer_2_clicked();

    void on_answer_3_clicked();

    void on_answer_4_clicked();

private:
    Ui::TestWindow *ui;
    ResultWindow *resultWindow;
};

#endif // TESTWINDOW_H
