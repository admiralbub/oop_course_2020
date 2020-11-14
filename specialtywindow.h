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

private slots:
    void on_site_nuzp_clicked();

    void on_menu_button_clicked();

private:
    Ui::SpecialtyWindow *ui;
};

#endif // SPECIALTYWINDOW_H
