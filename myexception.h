#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QException>
#include <string.h>
#include <iostream>
#include <QObject>
#include <QMessageBox>
#include <QCoreApplication>

#include <QApplication>

extern QApplication *pMainApp;

class MyException : QObject{
    Q_OBJECT

    Q_PROPERTY(QWidget* parentWidget READ parentWidget WRITE setParentWidget)
    Q_PROPERTY(QString developerFIO READ developerFIO WRITE setDeveloperFIO)
    Q_PROPERTY(QString developerEMail READ developerEMail WRITE setDeveloperEMail)
    Q_PROPERTY(QString developerTel READ developerTel WRITE setDeveloperTel)
    Q_PROPERTY(QString errorMessageTemplate READ errorMessageTemplate WRITE setErrorMessageTemplate)

public:
    MyException(QObject *parent = nullptr);

    Q_SLOT void throwException (QString msg, QString functionName);

    QWidget* parentWidget() const;
    Q_SLOT void setParentWidget(QWidget* parentWidget);

    QString developerFIO() const;
    Q_SLOT void setDeveloperFIO(QString developerFIO);

    QString developerTel() const;
    Q_SLOT void setDeveloperTel(QString developerTel);

    QString developerEMail() const;
    Q_SLOT void setDeveloperEMail(QString developerEMail);

    QString errorMessageTemplate() const;
    Q_SLOT void setErrorMessageTemplate(QString errorMessageTemplate);
    QString getErrorMessage(QString message, QString method);
public slots:


signals:


private:
    QWidget* m_parentWidget = nullptr;
    void quitApp();

    QString m_developerFIO;
    QString m_developerTel;
    QString m_developerEMail;
    QString m_errorMessageTemplate;
};

#endif // MYEXCEPTION_H
