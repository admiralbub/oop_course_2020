#ifndef HELPWINDOW_H
#define HELPWINDOW_H

#include <QMainWindow>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
namespace Ui {
class HelpWindow;
}

class HelpWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void firstWindow();
public:
    explicit HelpWindow(QWidget *parent = nullptr);
    ~HelpWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_further_clicked();

    void on_back_clicked();

private:
    Ui::HelpWindow *ui;
};

#endif // HELPWINDOW_H
