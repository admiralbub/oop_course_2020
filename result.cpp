#include "result.h"

Result::Result()
{

}

QString Result::getName() {
    return name;
}

QString Result::getCode() {
    return code;
}

double Result::getRes() {
    return res;
}

void Result::setName(QString sname) {
    name = sname;
}

void Result::setCode(QString scode) {
     code = scode;
}

void Result::setRes(double sres) {
    res = sres;
}

void Result::set(QString sname, QString scode, double sres) {
    name = sname;
    code = scode;
    res = sres;
}
