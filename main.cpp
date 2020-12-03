#include "mainwindow.h"
#include "resultwindow.h"
#include <QApplication>

#include "myexception.h"

QWidget *pMainWidget = nullptr;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MyException::setDeveloperEMail("artem.palamarchyuk@gmail.com");
    MyException::setDeveloperFIO("Артем Паламарчук");
    MyException::setDeveloperTel("+38 096 455 57 48");
    MyException::setErrorMessageTemplate("При работе программы возникла ошибка в методе {method}\nОшибка: {errorMsg}\n\nЗа детальной информацией обратитесь к разработчику. \n{developerEMail}\n{developerTel}\n{developerFIO}");

    try {
        //throw (MyException("test message", QString(Q_FUNC_INFO)));

        MainWindow *pMainWindows = new MainWindow;
        pMainWidget = pMainWindows;
        pMainWindows->setWindowTitle("Застосунок");
        pMainWindows->setWindowFlags(Qt::Dialog);
        pMainWindows->show();



    } catch (MyException &exception) {
        QMessageBox::critical(pMainWidget, exception.methodName(), exception.getErrorMessage());
        return -1;
    } catch (...){
        QMessageBox::critical(pMainWidget, "UNKNOWN_ERROR", "UNKNOWN_ERROR");
        return -1;
    }


    return a.exec();

}
