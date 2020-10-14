#ifndef RESULTWINDOW_H
#define RESULTWINDOW_H

#include <QMainWindow>
#include <specialitytest.h>
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

private:
    Ui::ResultWindow *ui;
    SpecialityTest *specialitytest;


};

#endif // RESULTWINDOW_H
