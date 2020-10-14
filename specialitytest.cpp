#include "specialitytest.h"
#include "ui_specialitytest.h"

SpecialityTest::SpecialityTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialityTest)
{
    ui->setupUi(this);
    setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);


}

SpecialityTest::~SpecialityTest()
{
    delete ui;
}
