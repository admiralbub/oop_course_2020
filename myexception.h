#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H
#include <QException>
#include <string.h>
#include <iostream>


class MyException : public QException
{
public:
    MyException();
    void Test(int test);
};

#endif // MYEXCEPTION_H
