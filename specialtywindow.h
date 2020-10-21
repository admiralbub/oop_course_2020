#ifndef SPECIALTYWINDOW_H
#define SPECIALTYWINDOW_H

#include <QMainWindow>

namespace Ui {
class SpecialtyWindow;
}

class SpecialtyWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void resultspecialy();
public:
    explicit SpecialtyWindow(QWidget *parent = nullptr);
    ~SpecialtyWindow();

private:
    Ui::SpecialtyWindow *ui;
};

#endif // SPECIALTYWINDOW_H
