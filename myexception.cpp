#include "myexception.h"

#include "mainwindow.h"

//устанавливаем статики
QString MyException::m_developerFIO = "";
QString MyException::m_developerTel = "";
QString MyException::m_developerEMail = "";
QString MyException::m_errorMessageTemplate = "";

MyException::MyException(QString message, QString methodName) : QException ()
{
    setMessage(message);
    setMethodName(methodName);
}

QString MyException::developerFIO()
{
    return m_developerFIO;
}

void MyException::setDeveloperFIO(QString developerFIO)
{
    m_developerFIO = developerFIO;
}

QString MyException::developerTel()
{
    return m_developerTel;
}

void MyException::setDeveloperTel(QString developerTel)
{
    if (m_developerTel == developerTel)
        return;

    m_developerTel = developerTel;
}

QString MyException::developerEMail()
{
    return m_developerEMail;
}

void MyException::setDeveloperEMail(QString developerEMail)
{
    m_developerEMail = developerEMail;
}

QString MyException::errorMessageTemplate()
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

QString MyException::getErrorMessage()
{
    return getErrorMessage(message(), methodName());
}

QString MyException::message() const
{
    return m_message;
}

QString MyException::methodName() const
{
    return m_methodName;
}

void MyException::setMessage(QString message)
{
    m_message = message;
}

void MyException::setMethodName(QString methodName)
{
    m_methodName = methodName;
}
