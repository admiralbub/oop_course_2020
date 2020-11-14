#ifndef SPECIALTYWINDOW_H
#define SPECIALTYWINDOW_H
#include "mydata.h"
#include <QMainWindow>
#include <resultwindow.h>
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

private slots:
    void on_site_nuzp_clicked();

    void on_menu_button_clicked();

private:
    Ui::SpecialtyWindow *ui;
    XML_Data *myData;
    ResultWindow *resultwindoW;
public:
    void WriteSpecialityinTextBrowser();
};

#endif // SPECIALTYWINDOW_H
