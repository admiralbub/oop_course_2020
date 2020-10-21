#include "specialitytest.h"
#include "ui_specialitytest.h"

SpecialityTest::SpecialityTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SpecialityTest)
{
    ui->setupUi(this);
    setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ Запорізька політехніка!");
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

    resultspecialy = new SpecialtyWindow();
    connect(resultspecialy, &SpecialtyWindow::resultspecialy, this, &SpecialityTest::show);

}

SpecialityTest::~SpecialityTest()
{
    delete ui;
}

void SpecialityTest::on_answer_1_clicked()
{
    resultspecialy->show();  // Показываем  окно о авторе
    this->close();    // Закрываем основное окно
}
