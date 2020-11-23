#include "mainwindow.h"
#include "resultwindow.h"
#include <QApplication>
#include "myexception.h"

MyException *pMyException;
QApplication *pMainApp;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    pMainApp = &a;

    pMyException = new MyException(&a);
    pMyException->setDeveloperEMail("artem.palamarchyuk@gmail.com");
    pMyException->setDeveloperFIO("Артем Паламарчук");
    pMyException->setDeveloperTel("+38 096 455 57 48");
    pMyException->setErrorMessageTemplate("При работе программы возникла ошибка в методе {method}\nОшибка: "
                                          "{errorMsg}\n\nЗа детальной информацией обратитесь к разработчику. "
                                          "\n{developerEMail}\n{developerTel}\n{developerFIO}");
    pMyException->setParentWidget(&w);
    w.setWindowTitle("Застосунок для вибору спеціальності для навчання в НУ «Запорізька політехніка»!");
    w.setWindowFlags(Qt::Dialog);
    w.show();
    return a.exec();
}





