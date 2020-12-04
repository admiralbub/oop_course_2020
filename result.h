#ifndef RESULT_H
#define RESULT_H

#include <QString>

class Result
{
public:
    Result();
    QString getName();
    QString getCode();
    double getRes();
    void setName(QString sname);
    void setCode(QString scode);
    void setRes(double sres);
    void set(QString sname, QString scode, double sres);
private:
    QString name;
    QString code;
    double res;
};

#endif // RESULT_H
