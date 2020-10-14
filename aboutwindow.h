#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();
signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();

    void on_back_clicked();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
