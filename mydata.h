#ifndef MYDATA_H
#define MYDATA_H

#include <QFile>
#include <QTextStream>
#include <QString>

class MyData
{
public:
    QFile file;
    MyData();
    void initFileAndOpenForRead(QString name_file);
private:
    QTextStream stream;
};
#endif // MYDATA_H
