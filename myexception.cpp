#include "myexception.h"
#include "mainwindow.h"

MyException::MyException(QObject *parent) : QObject(parent)
{

}

MyException::~MyException()
{

}

void MyException::throwException(QString msg, QString functionName)
{
    QString errorMsg = getErrorMessage(msg, functionName);
    QMessageBox::critical(m_parentWidget, QString ("Ошибка в %1").arg(functionName), errorMsg);
    quitApp();
}

QWidget *MyException::parentWidget() const
{
    return m_parentWidget;
}

void MyException::setParentWidget(QWidget *parentWidget)
{
    m_parentWidget = parentWidget;
}

QString MyException::developerFIO() const
{
    return m_developerFIO;
}

void MyException::setDeveloperFIO(QString developerFIO)
{
    m_developerFIO = developerFIO;
}

QString MyException::developerTel() const
{
    return m_developerTel;
}

void MyException::setDeveloperTel(QString developerTel)
{
    if (m_developerTel == developerTel)
        return;

    m_developerTel = developerTel;
}

QString MyException::developerEMail() const
{
    return m_developerEMail;
}

void MyException::setDeveloperEMail(QString developerEMail)
{
    m_developerEMail = developerEMail;
}

QString MyException::errorMessageTemplate() const
{
    return m_errorMessageTemplate;
}

void MyException::setErrorMessageTemplate(QString errorMessageTemplate)
{
    m_errorMessageTemplate = errorMessageTemplate;
}

QString MyException::getErrorMessage(QString message, QString method)
{
    QString tpl = m_errorMessageTemplate;
    return tpl.replace("{developerFIO}", m_developerFIO).
            replace("{developerEMail}", m_developerEMail).
            replace("{developerTel}", m_developerTel).
            replace("{errorMsg}", message).replace("{method}", method);
}

void MyException::quitApp()
{
    m_parentWidget->close();
    m_parentWidget->deleteLater();
}
