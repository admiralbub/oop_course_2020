#ifndef SPECIALITYTEST_H
#define SPECIALITYTEST_H

#include <QMainWindow>
#include <specialtywindow.h>
namespace Ui {
class SpecialityTest;
}

class SpecialityTest : public QMainWindow
{
    Q_OBJECT
signals:
    void resultwindow();
public:
    explicit SpecialityTest(QWidget *parent = nullptr);
    ~SpecialityTest();

private slots:
    void on_answer_1_clicked();

private:
    Ui::SpecialityTest *ui;
    SpecialtyWindow* resultspecialy;

};

#endif // SPECIALITYTEST_H
