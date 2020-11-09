#ifndef MYDATA_H
#define MYDATA_H

#include <QFile>
#include <QTextStream>
#include <QString>

class MyData
{
public:
    MyData();
    MyData(int number_questions);
    QFile file;
    QTextStream stream;
    int counter_question;
    int getNumberAlQuestions();
    void OpenForRead(QString name_file);
    void OpenForWrite(QString name_file);
    void CloseFile();
private:
    int number_all_questions;
    void InitFile(QString name_file);
};
#endif // MYDATA_H
