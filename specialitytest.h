#ifndef SPECIALITYTEST_H
#define SPECIALITYTEST_H

#include <QMainWindow>
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

private:
    Ui::SpecialityTest *ui;
};

#endif // SPECIALITYTEST_H
