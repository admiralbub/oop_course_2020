#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QException>

#include <QObject>
#include <QMessageBox>
#include <QCoreApplication>
#include <QApplication>
#include <QException>

class MyException : public QException {
public:
    MyException(QString message, QString methodName);

    void raise() const override { throw *this; }
    MyException *clone() const override { return new MyException(*this); }

    static QString developerFIO();
    static void setDeveloperFIO(QString developerFIO);

    static QString developerTel() ;
    static void setDeveloperTel(QString developerTel);

    static QString developerEMail();
    static void setDeveloperEMail(QString developerEMail);

    static QString errorMessageTemplate();
    static void setErrorMessageTemplate(QString errorMessageTemplate);

    QString getErrorMessage(QString message, QString method);
    QString getErrorMessage();

    QString message() const;
    void setMessage(QString message);

    QString methodName() const;
    void setMethodName(QString methodName);


private:

    static QString m_developerFIO;
    static QString m_developerTel;
    static QString m_developerEMail;
    static QString m_errorMessageTemplate;

    QString m_message;
    QString m_methodName;
};

#endif // MYEXCEPTION_H
